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
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
void solve_case() {
    int n; cin >> n;
    int q = 0;
    int mx = n + log2(n);
    auto ask = [&](int a, vi v) -> int {
        q++;
        cout << "? ";
        cout << 1 << " " << sz(v) << endl;
        cout << a+1 << endl;
        each(x, v) cout << x+1 << " ";
        cout << endl;
        int x; cin >> x;
        return x;
    };
    auto ask1 = [&](vi a, vi v) -> int {
        q++;
        cout << "? ";
        cout << sz(a) << " " << sz(v) << endl;
        each(x, a) cout << x+1 << " ";
        cout << endl;
        each(x, v) cout << x+1 << " ";
        cout << endl;
        int x; cin >> x;
        return x;
    };
    auto finish = [&](vi v) {
        cout << "! " << sz(v) << " ";
        each(x, v) cout << x+1 << " ";
        cout << endl;
    };
    auto get_post = [&](int id) -> vi {
        vi res;
        f1r(i, id, n) res.pb(i);
        return res;
    };
    auto get_range = [&](int l, int r) -> vi {
        vi res;
        f1r(i, l, r+1) res.pb(i);
        return res;
    };
    vi vals(n);
    f1r(i, 1, n) {
        if (ask(i, get_range(0, i-1)) != 0) {
            vals[i] = 1;
            f1r(j, i+1, n) vals[j] = ask1({i}, {j});
            int lo = 0;
            int hi = i-1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (ask1({i}, get_range(lo, mid)) != 0) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if (lo != hi) {
                if (ask1({i}, {lo}) != 0) {
                    vals[lo] = 1;
                } else {
                    vals[hi] = 1;
                }
            } else {
                vals[lo] = 1;
            }
            vi ans;
            f0r(j, n) if (vals[j] == 0) ans.pb(j);
            finish(ans);
            return;
        } 
    }   

}

/**
 * say you encountered a -1 before then
     * then the sum is -1
     * your current sum should be 0
 * say that you encountered a 1 before then
     * then the sum is 1
     * your current sum should be 0
     * either way, product should be -1
 * say you encountered nothing before then
     * 1, (S - 1)
     * you have to determine if something is before then
 */

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}