#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX*/

using namespace std;

using ll = long long;

#define mp make_pair

const int p = 998244353;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*const int N = 1000000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

const int N = (1<<14);

vector<int> bits(N);

void init()
{
    bits[0] = 0;
    for (int i = 1; i<N; i++)
    {
        bits[i] = bits[i/2];
        if (i%2) bits[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    /*for (int i = 0; i<8; i++) cout<<bits[i]<<' ';
    cout<<endl;*/

    int n;
    cin>>n;

    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];

    const int tot = (1<<n);
    const int check = (1<<(n - (n/2) - 1));

    vector<vector<vector<int>>> dp(tot, vector<vector<int>>(n, vector<int>(check)));

    for (int mask = 0; mask<tot; mask++) if (bits[mask] == 1)
    {
        for (int i = 0; i<n; i++) if (mask&(1<<i))
        {
            dp[mask][i][0] = 1;
        }
    }


    vector<int> rev(check);

    for (int i = 0; i<check; i++)
    {
        int i1 = i;
        for (int j = 0; j<(n - n/2 - 1); j++)
        {
            rev[i] = 2*rev[i] + i1%2;
            i1/=2;
        }
    }

    vector<vector<int>> cnt(n+1);
    for (int i = 0; i<tot; i++) cnt[bits[i]].push_back(i);


    /*for (auto it: rev) cout<<it<<' ';
    cout<<endl;*/


    /*for (int i = 0; i<tot; i++) cout<<bits[i]<<' ';
    cout<<endl;*/

    for (int cntbits = 2; cntbits<=(n+1)/2; cntbits++)
    {
        //cout<<"bits: "<<cntbits<<endl;
        for (auto mask: cnt[cntbits])
        {
            //cout<<"\t mask: "<<mask<<endl;
            for (int last = 0; last<n; last++) if (mask&(1<<last))
            {
                //cout<<"\t \t last: "<<last<<endl;
                int mask1 = mask^(1<<last);
                for (int prelast = 0; prelast<n; prelast++) if (mask1&(1<<prelast))
                {
                    //cout<<"\t \t \t prelast: "<<prelast<<endl;
                    for (int config = 0; config<check; config++) if (dp[mask1][prelast][config])
                    {
                        //cout<<"\t \t \t \t config: "<<config<<endl;
                        int newconfig = 2*config;
                        if (s[last][prelast]=='1') newconfig++;
                        //cout<<"\t \t \t \t newconfig: "<<newconfig<<endl;
                        dp[mask][last][newconfig]+=dp[mask1][prelast][config];
                        //cout<<"\t \t \t \t "<<dp[mask][last][newconfig]<<endl;
                    }
                }
            }
        }
    }

    /*for (int mask = 0; mask<tot; mask++)
    {
        for (int last = 0; last<n; last++) if (mask&(1<<last))
            for (int config = 0; config<check; config++)
                cout<<mask<<' '<<last<<' '<<config<<": "<<dp[mask][last][config]<<endl;
    }*/


    vector<ll> answer(1<<(n-1));
    for (auto l: cnt[n/2])
    {
        int r = (tot-1)^l;
        //cout<<l<<' '<<r<<endl;
        for (int last_l = 0; last_l<n; last_l++) if (l&(1<<last_l))
            for (int config_l = 0; config_l<check; config_l++) if (dp[l][last_l][config_l]!=0)
                for (int last_r = 0; last_r<n; last_r++) if (r&(1<<last_r))
                    for (int config_r = 0; config_r<check; config_r++) if (dp[r][last_r][config_r]!=0)
                    {
                        //cout<<"\t \t "<<config_l<<' '<<config_r<<endl;
                        int config = (config_l<<(n - n/2)) + rev[config_r];
                        //cout<<"\t \t "<<config<<endl;
                        if (s[last_l][last_r]=='1') config+=(1<<(n - n/2 - 1));
                        answer[config]+=1ll*dp[l][last_l][config_l]*dp[r][last_r][config_r];
                    }
    }

    for (auto it: answer) cout<<it<<' ';

}