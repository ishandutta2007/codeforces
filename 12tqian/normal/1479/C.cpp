#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


vector<array<int, 3>> ed;

void ae(int u, int v, int w) {
    ed.pb({u, v, w});
}

void ae(vector<vpi> g) {
    f0r(u, sz(g)) {
        each(e, g[u]) {
            ae(u, e.f, e.s);
        }
    }
}

vector<vpi> power2(int k) {
    if (k == 0) {
        return {{{1, 1}}, {}};
    }
    auto g = power2(k-1);
    g.pb(vpi());
    int sz = sz(g);
    f0r(i, sz-1) {
        each(e, g[i]) {
            if (e.f == sz-2) {
                g[i].eb(sz-1, e.s);
            }
        }
    }
    g[sz-2].eb(sz-1, (1<<(k-1)));
    return g;
}

void finish() {
    int n = 0;
    each(e, ed) {
        ckmax(n, e[0]);
        ckmax(n, e[1]);
    }
    n++;
    cout << n << " " << sz(ed) << '\n';
    each(e, ed) {
        cout << e[0]+1 << " " << e[1]+1 << " " << e[2] << '\n';
    }
    exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cout << "YES" << '\n';
    
    int L, R; cin >> L >> R;

    if (L == R) {
        ae(0, 1, L);
        finish();
    }

    int K = R - L + 1; // K >= 2
    K--;

    int len = 32 - __builtin_clz(K);
    vector<vpi> g = power2(len-1);
    const int FULL = (1 << 30) - 1;
    g.pb({});

    int sz = sz(g);
    for (int i = len-1; i >= 0; i--) {
        if ((1 << i) & K) {
            g[i+1].eb(sz-1, ((FULL - (1<<(i+1))+1) & K) + 1);
        }
    }
    g[0].eb(sz-1, 1);

    if (L > 1) {
        g.back().eb(sz(g), L-1);
        g.pb({});
    }

    ae(g);

    finish();
    return 0;
}