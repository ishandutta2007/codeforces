#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

class Dsu {
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <string> a(n);
    Dsu b(26);
    vector <bool> used(n);
    forn (i, 0, n) {
        cin >> a[i];
        for (auto j : a[i])
            used[j - 'a'] = true;
        forn (j, 1, sz(a[i])) {
            //cout << a[i][j] << " " << a[i][j - 1] << "\n";
            b.unite(a[i][j - 1] - 'a', a[i][j] - 'a');
        }
    }
    set <int> components;
    forn (i, 0, 26)
        if (used[i]) {
            //cout << i << " " << b.get(i) << "\n";
            components.insert(b.get(i));
        }
    cout << components.size();
    return 0;
}