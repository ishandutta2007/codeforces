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


//-----------------------------------------------------------------------------


ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

ll bpow(ll x, ll n, ll md) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % md;
        }
        x = x * x % md;
        n >>= 1;
    }
    return res;
}

vector<ll> pr;

ll phi(ll x) {
    ll y = 1;
    for (ll p : pr) {
        if (x % p) {
            continue;
        }
        ll g = 1;
        while (x % p == 0) {
            g *= p;
            x /= p;
        }
        y *= g - g / p;
    }
    return y;
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

ll inv(ll x, ll md) {
    if (x == 0) {
        return 0;
    }

    if (x == 1) {
        return 1;
    }

    return ((1 - inv(md % x, x) * md) / x + md);
}

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) {
    ll A = a.fst, d = a.snd;
    ll B = b.fst, D = b.snd;

    if (D < d) {
        swap(A, B);
        swap(D, d);
    }


    if (A == -1 || B == -1) {
        return mp(-1, -1);
    }

    ll g = gcd(d, D);



    if (A % g != B % g) {
        return mp(-1, -1);
    }

    ll u = A / g, v = B / g;
    D /= g, d /= g;

   // cout << bpow(d, phi(D) - 1, D) << " " << inv(d, D) << endl;
    /*if (bpow(d, phi(D) - 1, D) != inv(d, D)) {
        cout << "A " << D << " " << d << " "  << bpow(d, phi(D) - 1, D) << " " << inv(d, D) << endl;
        exit(0);
    }*/
    ll r = inv(d, D);
    ll x2 = (v - u) * r % D;
    if (x2 < 0) {
        x2 += D;
    }
    ll res = (u + x2 * d) % (d * D);


    res = res * g + A % g;



    if (res % (d * g) != A) {
        cout << "A" << endl;
        exit(0);
    }
    if (res % (D * g) != B) {
        cout << "B " << a << " " << b << endl;
        exit(0);
    }


    return mp(res, D * d * g);
}

const int maxn = 1e5 + 5;
int bp[maxn];
pair<ll, ll> rmq[18][maxn];

pair<ll, ll> get(int l, int r) {
    int k = bp[r - l + 1];
    return combine(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}


int solve(vector<pair<int,int>> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        rmq[0][i] = a[i];
    }

    for (int i = 1; i < 18; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            rmq[i][j] = combine(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }

    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        //assert(get(i, i).fst != -1);
        while (get(l, i).fst == -1) {
            l++;
        }

        chmax(ans, i - l + 1);
    }

    return ans;
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    for (int i = 1; i < maxn; i++) {
        while ((1 << bp[i]) <= i) {
            bp[i]++;
        }
        bp[i]--;
    }

    for (int i = 2; i <= 40; i++) {
        bool good = true;
        for (int j = 2; j < i; j++) {
            good &= bool(i % j);
        }
        if (good) {
            pr.pb(i);
        }
    }

    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<pair<int,int>>> a(m + 1);
    vector<int> len(n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        len[i] = k;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            a[x].pb(mp(i, j));
        }
    }

    vector<int> ans(m + 1);
    for (int i = 1; i <= m; i++) {

        for (int j = 0; j < a[i].size(); j++) {
            int k = j + 1;
            while (k < a[i].size() && a[i][k].fst - a[i][k - 1].fst == 1) {
                k++;
            }

            vector<pair<int,int>> b;
            for (int h = j; h < k; h++) {
                b.pb(mp(a[i][h].snd, len[a[i][h].fst]));
            }

            chmax(ans[i], solve(b));

            j = k - 1;
        }
    }


    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }



    return 0;
}