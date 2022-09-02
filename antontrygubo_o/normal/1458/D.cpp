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


void solve()
{
    string s;
    cin>>s;

    int n = s.size();
    vector<int> a(n+1);
    a[0] = 0;
    for (int i = 1; i<=n; i++)
    {
        a[i] = a[i-1]; if (s[i-1]=='1') a[i]++; else a[i]--;
    }

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;*/

    map<pair<int, int>, int> cnt;
    for (int i = 0; i<n; i++) cnt[mp(a[i], a[i+1])]++;

    int cur = 0;
    vector<int> res = {0};
    for (int i = 0; i<n; i++)
    {
        bool down = false;
        if (cnt[mp(cur, cur-1)])
        {
            if (cnt[mp(cur-1, cur)]>0 || cnt[mp(cur, cur+1)]==0) down = true;
        }
        if (down)
        {
            res.push_back(cur-1);
            cnt[mp(cur, cur-1)]--;
            cur--;
        }
        else
        {
            res.push_back(cur+1);
            cnt[mp(cur, cur+1)]--;
            cur++;
        }
    }

    for (int i = 0; i<n; i++) if (res[i+1]>res[i]) cout<<1; else cout<<0;
    cout<<'\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();
}