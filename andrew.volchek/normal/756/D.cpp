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
#include <limits>
#include <tuple>
#include <complex>
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//--------------------------------------------------------------------------

const ll mod = 1000000007;
const int maxn = 5005;

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll f[maxn], fi[maxn];

ll C(ll n, ll k) {
    if (k > n) {
        return 0;
    }
    return f[n] * fi[k] % mod * fi[n - k] % mod;
}

ll dp[maxn][27];
ll prv[26][maxn][27];
ll nprv[26][maxn][27];
ll ndp[maxn][27];


int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    f[0] = fi[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = bpow(f[i], mod - 2);
    }

    int n;
    cin >> n;
    //n = 5000;

    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
     //   s += 'a' + rand() % 26;
    }

    dp[0][26] = 1;


    for (int i = 0; i < s.size(); i++) {
        s[i] -= 'a';
        int c = s[i];


        for (int j = 0; j <= i + 1; j++) {
            for (int h = 0; h <= 26; h++) {
                nprv[s[i]][j][h] = dp[j][h];
            }
        }

        for (int j = 0; j <= i + 1; j++) {
            ll u = 0;
            for (int h = 0; h <= 26; h++) {
                if (s[i] != h) {
                    u += dp[j][h] - prv[c][j][h] + mod;
                }
            }

            u %= mod;
            dp[j + 1][c] += u;
            if (dp[j + 1][c] >= mod) {
                dp[j + 1][c] -= mod;
            }
        }



        for (int j = 0; j <= i + 1; j++) {
            for (int h = 0; h <= 26; h++) {
                prv[s[i]][j][h] = nprv[s[i]][j][h];
            }
        }


    }


    ll ans = 0;

    for (int i = 1; i <= s.size(); i++) {
        ll ss = 0;
        for (int j = 0; j < 26; j++) {
            ss += dp[i][j];
            ss %= mod;
        }

        ans += ss * C(s.size() - 1, i - 1) % mod;
    }
    ans %= mod;

    cout << ans << endl;

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;




    return 0;
}