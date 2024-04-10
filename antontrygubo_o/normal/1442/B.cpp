#include <bits/stdc++.h>

using namespace std;

/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using ll = long long;
using ld = long double;



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


mt19937 rnd(time(0));

/*
const int N = 1200000;

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


/*struct DSU
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

/*
int mex(set<int> a)
{
    int cur = 0;
    while (a.count(cur)) cur++;
    return cur;
}

void solve(vector<int> a)
{
    int n = a.size();

    vector<vector<int>> nim(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i<n-1; i++) nim[i][n-1] = 0;
    for (int r = n-2; r>=0; r--)
        for (int l = r-1; l>=0; l--)
        {
            set<int> lol;
            for (int j = r+1; j<n; j++) if (a[j]-a[r]>a[r]-a[l]) {lol.insert(nim[r][j]); dp[l][r] = max(dp[l][r], 1 + dp[r][j]);}
            nim[l][r] = mex(lol);
        }



    for (auto it: a) cout<<it<<' ';
    cout<<endl;

    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<n; j++) cout<<i<<' '<<j<<": "<<nim[i][j]<<' '<<dp[i][j]<<endl;
        cout<<endl;
    }

    //cout<<nim[0][1]<<endl;

}*/

void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for (auto &it: a) {cin>>it; it--;}
    vector<int> b(k);
    for (auto &it: b) {cin>>it; it--;}

    vector<int> pos(n);
    for (int i = 0; i<n; i++) pos[a[i]] = i;


    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;
    for (auto it: b) cout<<it<<' ';
    cout<<endl;*/

    map<int, int> prv;
    map<int, int> nxt;
    for (int i = 0; i<n-1; i++) nxt[a[i]] = a[i+1];
    nxt[a[n-1]] = n;
    for (int i = 1; i<n; i++) prv[a[i]] = a[i-1];
    prv[a[0]] = -1;

    vector<bool> needed(n);
    for (auto it: b) needed[it] = true;

    int res = 1;
    for (auto it: b)
    {
        int cnt = 0;
        //cout<<it<<' '<<prv[it]<<' '<<nxt[it]<<endl;
        if (prv[it]!=-1 && !needed[prv[it]]) cnt++;
        if (nxt[it]!=n && !needed[nxt[it]]) cnt++;
        res = mul(res, cnt);
        if (res==0) {cout<<0<<'\n'; return;}

        if (prv[it]!=-1 && !needed[prv[it]])
        {
            nxt[prv[prv[it]]] = it;
            prv[it] = prv[prv[it]];
        }
        else
        {
            prv[nxt[nxt[it]]] = it;
            nxt[it] = nxt[nxt[it]];
        }
        needed[it] = false;
        //cout<<it<<": "<<res<<endl;
    }
    cout<<res<<'\n';


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();



}

/*
1
7 4
1 4 7 3 6 2 5
3 2 4 5
 */