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

    int maxx = 1;

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
        maxx = max(maxx, sz[a]);
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    };
};*/



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;

    vector<ll> a(n), b(n);
    for (int i = 0; i<n; i++) cin>>a[i]>>b[i];

    ll A = 0; ll B = 0;

    for (int i = 0; i<n; i++) {A+=a[i]; B+=b[i];}

    ll maxx = (A+B)/k;

    if (A/k + B/k == maxx) {cout<<maxx; return 0;}

    vector<bool> dp(k);
    dp[0] = true;

    for (int i = 0; i<n; i++) if (a[i] + b[i]>=k)
    {
        vector<bool> dp1(dp);
        int l = max(0ll, k - b[i]); int r = min(k, a[i]);
        for (int j = 0; j<k; j++) if (dp[j])
        {
            for (int add = l; add<=r; add++) dp1[(j+add)%k] = true;
        }
        dp = dp1;
    }

    for (int i = 0; i<k; i++) if (dp[i])
    {
        if ((A-i)%k <= (A+B)%k) {cout<<maxx; return 0;}
    }

    cout<<maxx-1;
}