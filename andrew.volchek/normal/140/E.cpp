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
#include <complex>

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

const ld pi = acos(-1.0l);

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


//-----------------------------------------------------------------------------

const int maxn = 5005;
ll mod;

int st[maxn][maxn], st2[maxn][maxn], f[maxn];


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m >> mod;

    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * 1LL * i % mod;
    }

    st[0][0] = 1;
    st2[0][0] = 1;


    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            st[i][j] = st[i - 1][j - 1] * 1LL * (m - (j - 1)) % mod;
            st[i][j] += st[i - 1][j] * 1LL * (j - 1) % mod;
            if (st[i][j] >= mod) {
                st[i][j] -= mod;
            }

            st2[i][j] = st2[i - 1][j - 1];
            st2[i][j] += st2[i - 1][j] * 1LL * (j - 1) % mod;
            if (st2[i][j] >= mod) {
                st2[i][j] -= mod;
            }
        }
    }


    int x0;
    scanf("%d", &x0);

    vector<ll> dp(x0 + 1, 0);
    for (int i = 1; i <= x0; i++) {
        dp[i] = st[x0][i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);

        vector<ll> ndp(x + 1);
        ll s = 0;

        for (ll y : dp) {
            s += y;
            if (s >= mod) {
                s -= mod;
            }
        }


        for (int j = 1; j <= x; j++) {
            if (j < dp.size()) {
                ll os = s;
                s -= dp[j];
                if (s < 0) {
                    s += mod;
                }


                ndp[j] = s * 1LL * st[x][j] % mod;
                ndp[j] += dp[j] * 1LL * (st[x][j] + mod - (st2[x][j] * 1LL * f[j] % mod)) % mod;

                if (ndp[j] >= mod) {
                    ndp[j] -= mod;
                }

                s = os;
            } else {
                ndp[j] = s * st[x][j] % mod;
            }
        }

        dp = ndp;
    }

    ll ans = 0;
    for (ll y : dp) {
        ans = (ans + y) % mod;
    }

    cout << ans << endl;
    
    return 0;
}