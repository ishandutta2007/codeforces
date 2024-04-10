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
#define sz(x) (int)(x).size()
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

void solve_case() {
    int n, m; cin >> n >> m;
    vector<vi> f(m);
    f0r(i, m) {
        int k; cin >> k;
        f0r(j, k) {
            int x; cin >> x;
            x--;
            f[i].pb(x);
        }
    }

    vi used(n);
    vi ans(m);
    vi rem;
    f0r(i, m) {
        if (sz(f[i]) == 1) {
            int x = f[i].back();
            ans[i] = x;
            used[x]++;
        } else {
            rem.pb(i);
        }
    }
    int cap = (m + 1) / 2;
    each(e, used) {
        if (e > cap) {
            cout << "NO" << '\n';
            return;
        }
    }
    each(id, rem) {
        int x = f[id][0];
        int y = f[id][1];
        if (used[x] != cap) {
            used[x]++;
            ans[id] = x;
        } else {
            used[y]++;
            ans[id] = y;
        }
    }
    cout << "YES" << '\n';
    f0r(i, m) cout << ans[i] + 1 << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}

/**
 * bipartite graph
 * n people m  things
 * match so that 
 */