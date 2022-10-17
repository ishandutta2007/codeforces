#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }

const int N = 1005;

int n;

vector<vi> g;
vector<array<int, 3>> ed;
vi sz;


void dfs_size(int u, int p = -1) {
    sz[u] = 1;
    each(v, g[u]) {
        if (v == p) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}

int get_centroid(int u) {
    dfs_size(u);
    int num = sz[u];
    int p = -1;
    do { 
        int go = -1;
        each(v, g[u]) {
            if (v == p) continue;
            if (2 * sz[v] > num) {
                go = v;
            }
        }
        p = u;
        u = go;
    } while (u != -1);
    return p;
}

void solve(int u, int p, int L, int R, int B, int cur) {
    ed.pb({u, p, L * B - cur});
    // if (u == 3) {
    //     cout << L << " adsf asdf ads " << B << endl;
    // }
    cur += L * B - cur;
    L++;
    each(v, g[u]) {
        if (v == p) continue;
        solve(v, u, L, L + sz[v] - 1, B, cur);
        L += sz[v];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0); 
    int n; cin >> n;

    if (n == 1) {
        return 0;
    }

    g.resize(n);
    sz.resize(n);

    f0r(i, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int c = get_centroid(0);
    dfs_size(c);

    vi children = g[c];
    sort(all(children), [&](int x, int y) {
        return sz[x] < sz[y];
    });

    vi b1, b2;

    int bsum = 0;
    bsum += sz[children.back()];    
    b1.pb(children.back());
    children.pop_back();

    reverse(all(children));


    while (sz(children) && sz[children.back()] + bsum <= n/2) {
        bsum += sz[children.back()];
        b1.pb(children.back());
        children.pop_back();
    }

    each(t, children) b2.pb(t);

    // b1 stores        
    // b2 stores other thing
    int cur = 1;
    each(t, b1) {
        solve(t, c, cur, cur + sz[t] - 1, 1, 0);
        cur += sz[t];
    }
    // cout << c+1 << " asdf  " << bsum << endl;
    cur = 1;
    each(t, b2) {
        solve(t, c, cur, cur + sz[t] - 1, bsum + 1, 0);
        cur += sz[t];
    }

    each(e, ed) {
        cout << e[0]+1 << " " << e[1]+1 << " " << e[2] << '\n';
    }

    return 0;
}