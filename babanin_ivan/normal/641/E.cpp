#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef unsigned long long ull;

template <class T>
bool remin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool remax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const ld eps = 1e-7;

typedef ll ptdata;

struct pt {
    ptdata x, y;
    pt() {}
    pt(ptdata x, ptdata y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }
    pt operator + (const pt &r) const {
        return pt(x + r.x, y + r.y);
    }
    pt operator * (const ld &r) const {
        return pt(x * r, y * r);
    }
    ptdata sqlen() const {
        return abs(x * x + y * y);
    }
    ld len() const {
        return sqrtl(sqlen());
    }

    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ptdata cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ptdata dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}


ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

inline ll sqr(ll x) {
    return x * x;
}

struct Fenwick {
    vector<int> t;
    void init(int n) {
        t.assign(n, 0);
    }
    void inc(int p, ll val) {
        for (; p < t.size(); p |= (p + 1)) {
            t[p] += val;
        }
    }
    int sum(int r) {
        int ret = 0;
        for(; r >= 0; r &= (r + 1), --r) {
            ret += t[r];
        }
        return ret;
    }
    int sum(int l, int r) {
        r = min(r, int(t.size() - 1));
        l = max(l, 0);
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

struct Q {
    int a, t, x;
    int id;
};

const int N = 1000 * 1000;
Q q[N];
int ans[N];

inline void solve() {
    memset(ans, -1, sizeof(ans));
    int n = nxt();
    forn(i, n) {
        q[i].a = nxt();
        q[i].t = nxt();
        q[i].x = nxt();
        q[i].id = i;
    }
    stable_sort(q, q + n, [&](const Q &l, const Q &r) {
        if (l.x != r.x) return l.x < r.x;
        return l.id < r.id;
    });

    forn(i, n) {
        int j = i;
        vector<int> t;
        while (j < n && q[i].x == q[j].x) {
            t.pb(q[j].t);
            ++j;
        }
        sort(all(t));
        t.resize(unique(all(t)) - t.begin());
        Fenwick f;
        f.init((int)t.size());
        for (int k = i; k < j; ++k) {
            int p = lower_bound(all(t), q[k].t) - t.begin();
            if (q[k].a == 1) {
                f.inc(p, 1);
            }
            if (q[k].a == 2) {
                f.inc(p, -1);
            }
            if (q[k].a == 3) {
                ans[q[k].id] = f.sum(p);
            }
        }
        i = j - 1;
    }
    forn(i, n) {
        if (ans[i] != -1) {
            cout << ans[i] << "\n";
        }
    }
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}