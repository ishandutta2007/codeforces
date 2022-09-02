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

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}

    vector<vector<int>> pos(200);

    for (int i = 0; i<n; i++) pos[a[i]].push_back(i);

    int res = 0;

    for (int i = 0; i<200; i++) if (pos[i].size())
    {
        res = max(res, (int)(pos[i].size()));

        int k = pos[i].size();

        if (k==1) continue;

        vector<int> cnt(200);

        int l = k/2 - 1;
        int r = k - k/2;

        //cout<<l<<' '<<r<<endl;

        int maxx = 0;


        for (int j = pos[i][l] + 1; j<=pos[i][r]-1; j++) {cnt[a[j]]++; maxx = max(maxx, cnt[a[j]]);}

        //cout<<maxx<<endl;

        res = max(res, maxx + 2*(k/2));



        for (int j = k/2 - 2; j>=0; j--)
        {
            l--; r++;
            for (int s = pos[i][l] + 1; s<=pos[i][l+1]-1; s++) {cnt[a[s]]++; maxx = max(maxx, cnt[a[s]]);}
            for (int s = pos[i][r-1] + 1; s<=pos[i][r]-1; s++) {cnt[a[s]]++; maxx = max(maxx, cnt[a[s]]);}
            res = max(res, maxx + 2*(j+1));
        }
    }
    cout<<res<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();
}

/*
1
4
1 10 10 1
 */