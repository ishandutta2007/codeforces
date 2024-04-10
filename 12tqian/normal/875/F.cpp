#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

const int N = 1e5 + 5;

struct DSU {
    std::vector<int> e;
    std::vector<int> dead;

    void init(int n) {
        e = std::vector<int>(n, -1);
        dead = std::vector<int>(n, 0);
    }

    int get(int x) {
        return e[x] < 0 ? x : get(e[x]);
    }

    bool same_set(int a, int b) {
        return get(a) == get(b);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) std::swap(x, y);
        e[x] += e[y]; e[y] = x;
        dead[x] |= dead[y];
        return true;
    }

    int is_dead(int x) {
        return dead[get(x)];
    }

    void set_dead(int x) {
        dead[get(x)] = 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;

    vector<array<int, 3>> edges;

    f0r(i, m) {
        int r, c, a; cin >> r >> c >> a;
        r--, c--;
        edges.pb({a, r, c});
    }

    ll ans = 0;

    DSU D; D.init(n);

    sort(edges.rbegin(), edges.rend());

    trav(e, edges) {
        int r = e[1];
        int c = e[2];
        int w = e[0];
        if (!D.same_set(r, c)) {
            if (D.is_dead(r) && D.is_dead(c)) continue;
            D.unite(r, c);
            ans += w;
        } else {
            if (D.is_dead(r)) continue;
            else {
                D.set_dead(r);
                ans += w;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}