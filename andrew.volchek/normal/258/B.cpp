#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

const ll mod = 1000000007;
int a[20];

ll dp[20][20][2];
ll cnt[20];
ll dp2[20][7][65];

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    ll res = 1;
    if (n < k) {
        return 0;
    }
    for (int i = n; i >= n - k + 1; i--) {
        res = (res * i) % mod;
    }

    for (int i = 1; i <= k; i++) {
        res = (res * bpow(i, mod - 2)) % mod;
    }

    return res;
}

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    cin >> n;
    int p = 0;
    while (n) {
        a[p++] = n % 10;
        n /= 10;
    }
    reverse(a, a + p);

    dp[0][0][0] = 1;
    for (int pos = 0; pos < p; pos++) {
        for (int cnt = 0; cnt < 20; cnt++) {
            for (int ls = 0; ls < 2; ls++) {

                for (int c = 0; c <= (ls ? 9 : a[pos]); c++) {
                    if (c == 4 || c == 7) {
                        dp[pos + 1][cnt + 1][ls || c < a[pos]] += dp[pos][cnt][ls];
                        dp[pos + 1][cnt + 1][ls || c < a[pos]] %= mod;
                    } else {
                        dp[pos + 1][cnt][ls || c < a[pos]] += dp[pos][cnt][ls];
                        dp[pos + 1][cnt][ls || c < a[pos]] %= mod;
                    }
                }
            }
        }
    }


    for (int i = 0; i < 20; i++) {
        cnt[i] += dp[p][i][0] + dp[p][i][1];
        cnt[i] %= mod;
    }
    cnt[0] = (cnt[0] + mod - 1) % mod;

    for (int i = 0; i <= 6; i++) {
        dp2[0][i][0] = C(cnt[0], i);
    }


    for (int i = 1; i < 20; i++) {
        for (int p = 0; p <= 6; p++) {
            for (int cc = 0; cc < 65; cc++) {
                for (int k = 0; k * i <= cc; k++) {
                    if (p >= k) {
                        dp2[i][p][cc] += dp2[i - 1][p - k][cc - k * i] * C(cnt[i], k);
                        dp2[i][p][cc] %= mod;
                    }
                }
            }
        }
    }
    ll ans = 0;

    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < i; j++) {
            ans += cnt[i] * dp2[19][6][j] % mod;
        }
        ans %= mod;
    }


    for (int i = 1; i <= 6; i++) {
        ans = (ans * i) % mod;
    }

    cout << ans << endl;


    return 0;
}