#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MOD = (int)1e+9 + 7;


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif


    srand(42);

    int n, k;
    while (cin >> n >> k && n && k) {
    // for (;;) {
        // n = 1000;
        // k = 12;
        int a[n];

        vector <int> l(n, -1);
        vector <int> r(n, n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            // a[i] = rand() % 10;
        }

#ifdef LOCAL
        int answer = 0;
        {
            vector<int> b;
            for (int i = 0; i < n; ++i) {
                b.push_back(a[i]);
            }
            // dbg(b);
            while (b.size() >= k) {
                vector<int> c;
                for (int i = 0; i < b.size() - k + 1; ++i) {
                    int r = 0;
                    for (int j = 0; j < k; ++j) {
                        chmax(r, b[i + j]);
                    }
                    c.push_back(r);
                    answer = (answer + r) % MOD;
                }
                // dbg(c);
                b.swap(c);
            }
        }
#endif

        for (int iter = 0; iter < 2; ++iter) {
            stack <pair<int, int>> st;

            for (int i = 0; i < n; ++i) {
                int v = a[i] + iter;
                while (st.size() && st.top().first < v) {
                    st.pop();
                }
                if (st.size()) {
                    l[i] = st.top().second;
                }
                st.push(make_pair(a[i], i));
            }

            reverse(a, a + n);
            l.swap(r);
        }
        reverse(all(r));
        for (int i = 0; i < n; ++i) {
            if (r[i] != n) {
                r[i] = n - 1 - r[i];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll nr = (r[i] - i - 1) / (k - 1);
            ll nl = (i - l[i] - 1) / (k - 1);
            if (nr < nl) {
                swap(nl, nr);
            }
            ll c = (k + nl * (k - 1) + 1) * nl / 2 % MOD;
            ll m = min(r[i] - i, i - l[i]);
            c = (c + m * (nr - nl)) % MOD;
            ll len = (nr + 1) * (k - 1) + 1;
            if (r[i] - l[i] > len) {
                ll d = r[i] - l[i] - len;
                ll t = (d - 1) / (k - 1) + 1;
                c = (c + (d + d - (t - 1) * (k - 1)) * t / 2) % MOD;
            }
            // cerr << i << " " << a[i] << " " << c << " " << nl << " " << nr << endl;

            ans = (ans + c * a[i]) % MOD;
        }
        cout << ans << "\n";

#ifdef LOCAL
        if (ans != answer) {
            cout << "ans = " << ans << ", expected = " << answer << endl;
            cout << n << " " << k << endl;
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << a[i];
            }
            cout << endl;
            exit(1);
        }
#endif
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}