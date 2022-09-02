#include <bits/stdc++.h>

using namespace std;
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/
using ll = long long;
using ld = long double;



#define mp make_pair

const int p = 1e9 + 7;

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


mt19937 rnd(time(0));
/*

const int N = 1000005;

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
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


/*
struct DSU
{
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

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/


const int N = 100;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for (int i = 0; i<n; i++) cin>>a[i]>>b[i];

    vector<vector<int>> dp(n+1, vector<int>(N*n+1, -1e9));

    dp[0][0] = 0;

    for (int i = 0; i<n; i++)
    {
        for (int cnt = n; cnt>=1; cnt--)
            for (int sum = a[i]; sum<=N*n; sum++) dp[cnt][sum] = max(dp[cnt][sum], dp[cnt-1][sum-a[i]]+b[i]);
    }


    //cout<<dp[3][18]<<endl;

    //for (int i = 0; i<100; i++) cout<<i<<": "<<dp[3][i]<<endl;

    ll tot = 0;
    for (auto it: b) tot+=it;

    for (int cnt = 1; cnt<=n; cnt++)
    {
        ld answer = 0;
        for (int sum = 0; sum<=N*n; sum++) answer = max(answer, min((ld)(sum), (ld)(tot + dp[cnt][sum])/2));
        cout<<setprecision(10)<<fixed<<answer<<' ';
    }
}