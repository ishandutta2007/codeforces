#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

const int P = 998244353;

int mpow(ll b, ll e) {
    ll r = 1;
    while (e) { 
        if (e & 1) { 
            r *= b;
            r %= P;
        }
        b *= b;
        b %= P;
        e >>= 1;
    }  
    return r;
}
int minv(ll b) { return mpow(b, P - 2); }
int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int madd(int& x, int y) { return x = add(x, y); }
int mult(int x, int y) { return 1LL * x * y % P; }
int mmult(int& x, int y) { return x = mult(x, y); }

const int N = 2e5 + 10;

template <class T> struct Container { 
    int num = 0;
    Tree<pair<T, int>> use;
    void add(T x) {
        use.insert(mp(x, num++));
    } 
    int more(T x) { // strictly greater
        return sz(use) - use.order_of_key(mp(x, num + 1));
    }
};

ll a[N];
ll pre[N];
ll suf[N];
ll p[N];

int solve(vl a, ll val) {
    int ans = 0;
    int n = sz(a);
    a.insert(a.begin(), 0); 
    vl pre(n + 2);
    vl suf(n + 2);
    vl p(n + 2);
    f1r(i, 1, n + 1) {
        pre[i] = pre[i - 1] + a[i];
        if (i % 2 == 1) {
            p[i] = p[i - 1] + a[i];
        } else {
            p[i] = p[i - 1] - a[i];
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    vector<Container<ll>> c(2);
    for (int i = n; i >= 1; i--) { 
        int par = i % 2;
        if (par == 0) {
            madd(ans, c[1].more(val + pre[i] - p[i]));
        } else {
            madd(ans, c[0].more(val + pre[i] + p[i]));
        }
        if (i <= n - 2) {
            if (par == 0) {
                c[0].add(suf[i + 2] + p[i + 1]);
            } else {
                c[1].add(suf[i + 2] - p[i + 1]);
            }
        }
    }
    return ans;
}

void solve_case(int tc = 0) {
    int n; cin >> n;
    f0r(i, n + 5) a[i] = pre[i] = suf[i] = p[i] = 0;
    f1r(i, 1, n + 1) cin >> a[i];
    int ans = 0;
    if (n <= 2) { // take care of small cases
        f0r(msk, (1 << n)) {
            ll sum = 0;
            f0r(i, n) {
                if ((1 << i) & msk) {
                    sum -= a[i + 1];
                } else {
                    sum += a[i + 1];
                }
            }
            if (sum > 0) {
                madd(ans, 1);
            }
        }
        cout << ans << '\n';
        return;
    }
    f1r(i, 1, n + 1) {
        pre[i] = pre[i - 1] + a[i];
        if (i % 2 == 1) p[i] = p[i - 1] + a[i];
        else p[i] = p[i - 1] - a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    { // all one kind
        madd(ans, 1); // PPPP
    } 
    { // no consec
        if (p[n] != 0) { // PCPC, CPCP
            madd(ans, 1);
        }
    }
    { // both exist and one consec
        // CCPCPCP
        // PCCPCPC
        f1r(i, 2, n + 1) {
            ll post = p[n] - p[i];
            if (i % 2 == 1) { 
                post *= -1;
            }
            if (i != n && post - pre[i] > 0) {
                madd(ans, 1);
            }
            if (i >= 3 && post - pre[i] + 2 * a[1] > 0) {
                madd(ans, 1);
            }
        }
        // CPCPCPP
        // PCPCPPC
        for (int i = n - 1; i >= 1; i--) { 
            ll pref = p[i - 1];
            if ((i - 1) % 2 == 1) {
                pref *= -1;
            }
            if (i != 1 && pref + pre[n] - pre[i - 1] > 0) {
                madd(ans, 1);
            }
            if (i <= n - 2 && pref + pre[n] - pre[i - 1] - 2 * a[n] > 0) {
                madd(ans, 1);
            }
        }
    }
    // cout << ans << endl;
    { // both exist and two consec
        f1r(i, 2, n - 1) { // PPCC
            if (suf[i + 1] < pre[i]) {
                madd(ans, 1);
            }
        }
        // CCPCPCPCPP
        madd(ans, solve(vl(a + 1, a + n + 1), 0));
        // PCCPP
        madd(ans, solve(vl(a + 2, a + n + 1), -a[1]));
        // CCPPC
        madd(ans, solve(vl(a + 1, a + n), a[n]));
        // PCCPPC
        madd(ans, solve(vl(a + 2, a + n), -a[1] + a[n]));
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    f1r(tc, 1, tt + 1) solve_case(tc);
    return 0;
}

/** 
 * C gaps are nondec
 * P gaps are noninc
 * If there are two C's consecutive
     * everything before was either C, or all P
 * If there are two P's consecutive
     * everything after was either all P or all C
 * all of one kind
 * CCCC G
 * PPPP G
 * no consec
 * PCPC G
 * CPCP G
 * both exist and one consec
 * CCPCPCP
 * PCCPCPC
 * 
 * CPCPCPP
 * PCPCPPC
 * both exist and two consec
 * 
 * PPCC 
 * CCPCPCPCPP
 * 
 * CCPCPCPP 
 * Say from L >= 1, R <= n, (L + R) == 1 mod 2, L < R - 1
 * 1, -1, 1, -1
 * L is even, R odd
 * pre[L] - p[L] < suf[R] - p[R - 1]
 * L is odd, R even
 * pre[L] + p[L] < suf[R] + p[R - 1]
 */