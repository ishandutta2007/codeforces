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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m;
    while (cin >> n >> m) {
        ll s[n], a[n], b[n];
        ll k = 0;

        vector <pair<ll, ll>> v[2];
        ll t[2];
        memset(t, 0, sizeof(t));

        ll answer = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> a[i] >> b[i];
            answer += max(a[i], b[i]) * s[i];
            k += s[i];

            if (a[i] == b[i]) {
                continue;
            }
            int c = a[i] > b[i];
            v[c].emplace_back(abs(a[i] - b[i]), s[i]);
            t[c] += s[i];
        }
        k = (k + m - 1) / m;
        if ((t[0] + m - 1) / m + (t[1] + m - 1) / m > k) {
            ll cost = 0;
            for (int i = 0; i < 2; ++i) {
                auto& a = v[i];
                sort(a.begin(), a.end());
                ll s = t[i] % m;
                ll r = answer;
                for (auto& p : a) {
                    ll d = min((ll)p.second, s);
                    s -= d;
                    r -= p.first * d;
                    if (s == 0) {
                        break;
                    }
                }
                if (i == 0 || cost < r) {
                    cost = r;
                }
            }
            answer = cost;
        }
        cout << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}