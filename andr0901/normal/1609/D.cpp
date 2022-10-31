//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

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

    int get_size(int v) {
        return sz[get(v)];
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
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    int free = 0;
    multiset<int> components;
    forn (i, 0, n) {
        components.insert(1);
    }
    auto erase = [&](int x) {
        components.erase(components.find(x));
    };
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        if (dsu.get(v) == dsu.get(u)) {
            ++free;
        } else {
            erase(dsu.get_size(v));
            erase(dsu.get_size(u));
            dsu.unite(v, u);
            components.insert(dsu.get_size(v));
        }
        int k = 0;
        int ans = -1;
        for (auto it = components.rbegin(); it != components.rend(); ++it) {
            if (k == free + 1) {
                break;
            }
            ++k;
            ans += *it;
        }
        cout << ans << "\n";
        cerr << free << "\n";
    }
    return 0;
}