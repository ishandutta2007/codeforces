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

ll dp[20][2][20];

ll foo(ll r, int len, int k) {

    vector<int> a(len);

    for (int i = len - 1; i >= 0; i--) {
        a[i] = r % 10;
        r /= 10;
    }

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < 2; j++) {
            for (int u = 0; u <= len; u++) {
                dp[i][j][u] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < len; i++) {
        for (int ls = 0; ls < 2; ls++) {
            for (int cnt = 0; cnt <= len; cnt++) {
                for (int d = 0; d <= (ls ? 9 : a[i]); d++) {
                    dp[i + 1][ls || d < a[i]][d == 9 ? (cnt + 1) : 0] += dp[i][ls][cnt];
                }
            }
        }
    }

    ll ans = 0;
    for (int cnt = k; cnt <= len; cnt++) {
        ans += dp[len][0][cnt] + dp[len][1][cnt];
    }

    return ans;
}

ll foo(ll l, ll r, int len, int k) {
    if (l > r) {
        return 0;
    }

    return foo(r, len, k) - (l ? foo(l - 1, len, k) : 0);
}

string toS(ll x, int len) {
    string res(len, '0');
    for (int i = len - 1; i >= 0; i--) {
        res[i] = '0' + (x % 10);
        x /= 10;
    }
    return res;
}

ll solve(ll h, ll m, ll h1, ll m1, ll h2, ll m2, ll k) {
    int lenH = to_string(h - 1).size();
    int lenM = to_string(m - 1).size();


    int diffM = 0;
    auto a = toS(0, lenM), b = toS(m - 1, lenM);
    for (int i = 0; i < lenM; i++) {
        diffM += a[i] != b[i];
    }


    ll ans = 0;

    if (h1 < h2) {
        ans += foo(h1, h2 - 1, lenH, max(0LL, k - 1 - diffM));

        if (m1 < m - 2) {
            ans += foo(m1, m - 2, lenM, k - 1);
        }

        if (0 < m2 - 1) {
            ans += foo(0, m2 - 1, lenM, k - 1);
        }

        ans += (h2 - h1 - 1) * foo(0, m - 2, lenM, k - 1);
    } else {
        ans = foo(m1, m2 - 1, lenM, k - 1);
    }

    return ans;
}

ll brute(ll h, ll m, ll h1, ll m1, ll h2, ll m2, ll k) {
    ll res = 0;
    ll x = h1, y = m1;

    int lenH = to_string(h - 1).size();
    int lenM = to_string(m - 1).size();


    while (true) {
        ll u = x, v = y;
        v++;
        if (v == m) {
            v = 0;
            u++;
        }

        if (u == h) {
            u = 0;
        }

        auto a = toS(x, lenH) + toS(y, lenM);
        auto b = toS(u, lenH) + toS(v, lenM);

        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += a[i] != b[i];
        }

        if (k <= diff) {
            res++;
        }


        if (u == h2 && v == m2) {
            break;
        }

        x = u, y = v;
    }

    return res;
}

int main() {

    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    ll h, m, k;
    cin >> h >> m >> k;

    ll h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int lenH = to_string(h - 1).size();
    int lenM = to_string(m - 1).size();


    ll res = 0;

    if (mp(h1, m1) <= mp(h2, m2)) {
        res = solve(h, m, h1, m1, h2, m2, k);
    } else {
        res = solve(h, m, h1, m1, h - 1, m - 1, k);
        res += solve(h, m, 0, 0, h2, m2, k);

        auto a = toS(0, lenH) + toS(0, lenM);
        auto b = toS(h - 1, lenH) + toS(m - 1, lenM);

        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += a[i] != b[i];
        }

        if (k <= diff) {
            res++;
        }
    }

    cout << res << endl;
    //assert(res == brute(h, m, h1, m1, h2, m2, k));

    return 0;
}