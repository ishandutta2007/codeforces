#include <bits/stdc++.h>

using namespace std;

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
    };
};*/

/*const int N = 1200000;

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
/*
const int T = 4;

vector<vector<int>> produce(int n)
{
    vector<int> kek;
    for (int i = 0; i<T*T; i++)
    {
        kek.push_back(n%3); n/=T;
    }
    vector<vector<int>> a(T, vector<int>(T));
    for (int i = 0; i<T; i++)
        for (int j = 0; j<T; j++) a[i][j] = kek[T*i+j];

   return a;
}

int ans(vector<vector<int>> a)
{
    set<int> sums;
    for (int i = 0; i<T; i++)
    {
        int s = 0;
        for (int j = 0; j<T; j++) s+=a[i][j];
        sums.insert(s);
    }
    for (int i = 0; i<T; i++)
    {
        int s = 0;
        for (int j = 0; j<T; j++) s+=a[j][i];
        sums.insert(s);
    }
    return sums.size();
}*/

void solve()
{
    int n, k;
    cin>>n>>k;

    vector<int> cnt(k+1);

    int t;
    for (int i = 0; i<n; i++)
    {
        cin>>t; cnt[t]++;
    }

    vector<int> lim(k+1);
    for (int i = 1; i<=k; i++) cin>>lim[i];

    ll sz = 0;

    ll cursum = 0;

    for (int i = k; i>=1; i--)
    {
        cursum+=cnt[i];
        sz = max(sz, (cursum+lim[i]-1)/lim[i]);
    }

    vector<vector<int>> ans(sz);

    vector<int> guys;
    for (int i = k; i>=1; i--)
        for (int j = 0; j<cnt[i]; j++) guys.push_back(i);

    for (int i = 0; i<guys.size(); i++) ans[i%sz].push_back(guys[i]);

    cout<<ans.size()<<endl;
    for (auto it: ans)
    {
        cout<<it.size()<<' ';
        for (auto x: it) cout<<x<<' ';
        cout<<endl;
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    //cin>>t;
    while (t--) solve();


}