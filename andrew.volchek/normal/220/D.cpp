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

ll add(ll x, ll y) {
    return (x + y) % mod;
}

ll sub(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

const int maxn = 4005;

int g[maxn][maxn];

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

ll brute(int n, int m) {
    int res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int i2 = 0; i2 <= n; i2++) {
                for (int j2 = 0; j2 <= m; j2++) {
                    for (int i3 = 0; i3 <= n; i3++) {
                        for (int j3 = 0; j3 <= m; j3++) {
                            ll s = (i2 - i) * (j3 - j) - (j2 - j) * (i3 - i);
                            if (s && s % 2 == 0) {
                                //if (i != i2 || i2 != i3 || i3 != i)
                                res++;
                            }
                        }
                    }
                }
            }
        }
    }

    return res;
}

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    ll ans = 0;

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            g[i][j] = 1;
        }
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            //assert(gcd(i, j) == g[i][j]);
            if (g[i][j] == 1) {
                for (int k = 2; i * k < maxn && j * k < maxn; k++) {
                    g[i * k][j * k] = k;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        int a = 0 - i;
        int b = n - i;

        ll u[2];

        if (a & 1) {
            u[1] = 1 + (b - a) / 2;
            u[0] = b - a + 1 - u[1];
        } else {
            u[0] = 1 + (b - a) / 2;
            u[1] = b - a + 1 - u[0];
        }


        for (int j = 0; j <= m; j++) {
            int c = 0 - j;
            int d = m - j;

            ll v[2];

            if (c & 1) {
                v[1] = 1 + (d - c) / 2;
                v[0] = d - c + 1 - v[1];
            } else {
                v[0] = 1 + (d - c) / 2;
                v[1] = d - c + 1 - v[0];
            }

            ll s = (u[0] + u[1]) * (v[0] + v[1]) % mod;

            ll x = s - u[1] * v[1] + mod;
            x %= mod;
            ans = (ans + x * x) % mod;

            x = u[1] * v[1];
            x %= mod;
            ans = (ans + x * x) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll x = g[i][j];
            ll d = (mod - (x - 1)) * 12LL;
            d *= (n + 1 - i) * (m + 1 - j);
            d %= mod;
            ans = (ans + d) % mod;
        }
    }

    ans -= (n + 1) * 1LL * n  % mod * (n - 1) % mod * (m + 1) % mod;
    ans -= (m + 1) * 1LL * m  % mod * (m - 1) % mod * (n + 1) % mod;

    ans %= mod;
    ans += mod;
    ans %= mod;


    ll x = (n + 1) * 1LL * (m + 1) % mod;

    ans -= x * (x + mod - 1) % mod * 3LL % mod;
    ans %= mod;
    ans += mod;
    ans %= mod;

    ans -= x;
    ans %= mod;
    ans += mod;
    ans %= mod;


    cout << ans << endl;
    //cout << brute(n, m) << endl;

    return 0;
}