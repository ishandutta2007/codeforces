#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MOD = (int)1e+9 + 7;

typedef long long ll;

int n;
vector < pair < int, int > > a;
vector < int > f;

int powmod(const int a, const int b)
{
    if (b == 0) {
        return 1;
    }
    ll r = powmod(a, b >> 1);
    (r *= r) %= MOD;
    return b & 1? r * a % MOD : r;
}

int divmod(const int a, const int b)
{
    return a * (ll)powmod(b, MOD - 2) % MOD;
}

int C(int n, int m)
{
    return divmod(divmod(f[n], f[m]), f[n - m]);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> n;
    f.resize(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * (ll)i % MOD;
    }
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x) {
            a.push_back(make_pair(x, i));
        }
    }
    sort(a.begin(), a.end());
    if (a.size() == 0) {
        cout << powmod(2, n - 1) << endl;
        return 0;
    }

    int ans = 0;
    for (int d = -1; d <= 1; d += 2) {
        int l = a[0].second + d * (a[0].first - 1), r = a[0].second;
        if (l > r) {
            swap(l, r);
        }
        if (l < 1 || n < r || (l == r && d == 1)) {
            continue;
        }

        ll res = 1;
        
        for (size_t i = 1; i < a.size(); ++i) {
            bool f = false;
            for (int j = -1; j <= 1; j += 2) {
                int L = a[i].second + j * (a[i].first - 1), R = a[i].second + j;
                if (L > R) {
                    swap(L, R);
                }
                if (L < 1 || n < R || R < r || l < L) {
                    continue;
                }
                (res *= C(l - L + R - r, l - L)) %= MOD;
                f = true;
                l = L;
                r = R;
                if (r < a[i].second) {
                    ++r;
                } else {
                    --l;
                }
                break;
            }
            if (!f) {
                res = 0;
                break;
            }
        }
        if (res) {
            int L = 1, R = n;
            (res *= C(l - L + R - r, l - L)) %= MOD;
        }
        (ans += res) %= MOD;
    }
    if (a[0].first > 1) {
        ans = ans * (ll)powmod(2, a[0].first - 2) % MOD;
    }
    cout << ans << endl;
	return 0;
}