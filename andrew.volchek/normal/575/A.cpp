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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair <U, V> &x) {
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


//-----------------------------------------------------------------------------

ll p;

struct M {
    ll a[2][2];

    M() {
        for (int i = 0; i < 2; i++) {
            fill(a[i], a[i] + 2, 0);
        }
    }

    static M one() {
        M res;
        for (int i = 0; i < 2; i++) {
            res.a[i][i] = 1;
        }
        return res;
    }

    M(ll x, ll y) {
        a[0][0] = 0, a[0][1] = 1;
        a[1][0] = x, a[1][1] = y;
    }

    void print() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    M operator * (const M &o) const {
        M res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % p;
                }
            }
        }

        return res;
    }
};


const int maxn = 1e5 + 5;

M t[maxn * 4];

pair<ll, ll> s[maxn];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = M(s[l].fst, s[l].snd);
        return;
    }

    int c = (l + r) >> 1;

    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);

    t[v] = t[2 * v + 1] * t[2 * v];
}

M get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return t[v];
    }

    M res = M::one();
    int c = (l + r) >> 1;

    if (i <= c) {
        res = get(2 * v, l, c, i, j) * res;
    }

    if (c < j) {
        res = get(2 * v + 1, c + 1, r, i, j) * res;
    }

    return res;
}

vector<ll> a;
map<ll, ll> unusual;

ll get(ll p) {
    if (unusual.count(p)) {
        return unusual[p];
    } else {
        return a[p % a.size()];
    }
}

M getM(ll x) {
    return M(get(x), get(x + 1));
}

M bpow(M x, ll n) {
    M res = M::one();
    while (n) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

M brute(vector<int> a, int k) {
    M res = M::one();
    for (int i = 0; i < k - 1; i++) {
        res = M(a[i], a[i + 1]) * res;
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
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif


    ll k;
    cin >> k >> p;

    vector<int> f(100);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    for (int i = 0; i < 100; i++) {
        f[i] = a[i % n];
    }

    for (int i = 0; i < n; i++) {
        s[i] = mp(a[i], a[(i + 1) % n]);
    }

    build(1, 0, n - 1);

    int m;
    cin >> m;

    set<ll> nice;

    if (k == 0) {
        cout << 0 << endl;
        return 0;
    } else if (k == 1) {
        cout << (1 % p) << endl;
        return 0;
    }

    nice.insert(k - 2);


    for (int i = 0; i < m; i++) {
        ll j, v;
        cin >> j >> v;
        unusual[j] = v;
        //f[j] = v;
        nice.insert(j - 1);
        nice.insert(j);
    }

    ll pos = 0;
    M ans = M::one();

    while (true) {
        ll nxt = *nice.lower_bound(pos);

        if (nxt == pos) {
            ans = getM(pos) * ans;
            pos++;

            if (pos == k - 1) {
                break;
            }
            continue;
        }

        ll u = pos / n, v = nxt / n;

        if (u == v) {
            ans = get(1, 0, n - 1, pos % n, (nxt - 1) % n) * ans;
            pos = nxt;
        } else {
            if (pos % n) {
                ans = get(1, 0, n - 1, pos % n, n - 1) * ans;
                pos += (n - (pos % n));
            } else {
                ll need = v - u;
                ans = bpow(get(1, 0, n - 1, 0, n - 1), need) * ans;
                pos += need * n;
            }
        }
    }

    //ans.print();
    //brute(f, k).print();
    cout << ans.a[1][1];

    return 0;
}