

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    auto fail = [&]() {
        cout << -1 << '\n';
        exit(0);
    };
    int n; cin >> n;
    vpi v(n);
    f0r(i, n) cin >> v[i].f >> v[i].s, v[i].f--, v[i].s--;
    f0r(i, n) {
        if (v[i].f < n && v[i].s < n) fail();
        if (v[i].f >= n && v[i].s >= n) fail();
    }
    map<pi, int> state;
    f0r(i, n) {
        int val;
        if (v[i].f <= v[i].s) {
            val = 0;
        } else {
            val = 1;
            swap(v[i].f, v[i].s);
        }
        state[v[i]] = val;
    }
    sort(all(v));
    vi idx(2 * n);
    f0r(i, n) {
        idx[v[i].f] = idx[v[i].s] = i;
    }
    set<int> in;
    f0r(i, 2 * n) in.insert(i);
    pi cur({-1, -1});
    auto contains = [](pi x, pi y) -> bool { 
        if (x.f > y.f) swap(x, y);
        if (x.f < y.f && y.s < x.s) return true;
        return false;
    };
    auto destroy = [&](int x) {
        in.erase(v[x].f);
        in.erase(v[x].s);
    };
    int ans = 0;
    while (sz(in)) {
        vi dp(2);
        int le = idx[*in.begin()];
        int ri = idx[*in.rbegin()];
        if (le == ri) {
            destroy(le);
            continue;
        }   
        destroy(le);
        destroy(ri);
        int sl = state[v[le]];
        int sr = state[v[ri]];
        if (sl == 0 && sr == 0) {
            dp[0]++;
            dp[1]++;
        } else if (sl == 0 && sr == 1) {
            dp[1] += 2;
        } else if (sl == 1 && sr == 0) {
            dp[0] += 2;
        } else if (sl == 1 && sr == 1) {
            dp[0]++;
            dp[1]++;
        }
        if (cur.f != -1 && !contains(v[cur.f], v[le])) fail();
        if (cur.s != -1 && !contains(v[cur.s], v[ri])) fail();
        cur.f = le;
        cur.s = ri;
        while (true) {
            bool done = true;
            while (sz(in) && v[idx[*in.begin()]].f < v[cur.s].f) {
                int id = idx[*in.begin()];
                if (!contains(v[cur.f], v[id])) fail();
                if (state[v[id]] == 0) {
                    dp[1]++;
                } else {
                    dp[0]++;
                }
                destroy(id);
                cur.f = id;
                done = false;
            }
            while (sz(in) && v[idx[*in.rbegin()]].s > v[cur.f].s) {
                int id = idx[*in.rbegin()];
                if (!contains(v[cur.s], v[id])) fail();
                if (state[v[id]] == 1) {
                    dp[1]++;
                } else {
                    dp[0]++;
                }
                destroy (id);
                cur.s = id;
                done = false;
            }
            if (done) break;
            // else assert(false);
        }
        ans += min(dp[0], dp[1]);
        // cout << dp[0] << " " << dp[1] << endl;
    }
    cout << ans << '\n';
    return 0;
}

/** 
 * Construct interval graph
 * Special case where the intervals are all gap intervals
 * We create a DAG
 */