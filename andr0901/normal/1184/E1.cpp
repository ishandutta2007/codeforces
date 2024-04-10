#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
 
int nxt() {
    int x;
    cin >> x;
    return x;
}
 
struct Edge {
    int v, u, w;
};
 
struct Dsu {
private:
    int n;
    vector <int> p, sz;
public:
    Dsu(int _n) {
        n = _n;
        p.resize(n, -1);
        sz.resize(n, 1);
    }
 
    int get(int v) {
        if (p[v] == -1)
            return v;
        return p[v] = get(p[v]);
    }
 
    void unite(int v, int u) {
        v = get(v), u = get(u);
        if (v == u)
            return;
        if (sz[v] > sz[u])
            swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
    }
};
 
int n;
 
bool check(int m, vector <Edge>& b) {
    b[0].w = m;
    auto a = b;
    auto cmp = [&](Edge a, Edge b){return a.w < b.w;};
    int ans2 = m; {
        Dsu x(n);
        x.unite(a[0].v, a[0].u);
        sort(a.begin() + 1, a.end(), cmp);
        forn (i, 1, sz(a)) {
            if (x.get(a[i].v) != x.get(a[i].u)) {
                ans2 += a[i].w;
                x.unite(a[i].v, a[i].u);
            }
        }
    }
    int ans1 = 0; {
        Dsu x(n);
        sort(a.begin(), a.end(), cmp);
        forn (i, 0, sz(a)) {
            if (x.get(a[i].v) != x.get(a[i].u)) {
                ans1 += a[i].w;
                x.unite(a[i].v, a[i].u);
            }
        }
    }
    //cout << m << " " << ans1 << " " << ans2 << "\n";
    return ans1 == ans2;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    n = nxt();
    int m = nxt();
    vector <Edge> a(m);
    forn (i, 0, m) 
        a[i] = {nxt() - 1, nxt() - 1, nxt()};
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m, a)) 
            l = m;
        else 
            r = m;
    }
    cout << l;
    return 0;
}