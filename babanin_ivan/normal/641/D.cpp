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

template<typename T>
inline T sqr(T x) {
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

const int N = 1000 * 100;
ld a[N];
ld b[N];
ld aa[N];
ld bb[N];

const ld eps = 1e-8;

inline void solve() {
    int n;
    cin >> n;
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, n) {
        cin >> b[i];
    }
    ld sa = 0;
    ld sb = 0;
    {
        ld ab = a[0] + b[0];
        ld pp = a[0];
        ld dd = fabsl(ab * ab - 4 * pp);
        dd = sqrtl(dd);
        aa[0] = (ab - dd) / 2.0;
        bb[0] = (ab + dd) / 2.0;
        sa += aa[0];
        sb += bb[0];
    }
    while (true) {
        sa = aa[0];
        sb = bb[0];
        bool ok = true;
        for (int i = 1; i < n && ok; ++i) {
            // sa * p2 + sb * p1 + p1 * p2 = a[i]
            // p1 + p2 = a[i] + b[i]
            // p1 = x
            ld ab = a[i] + b[i];
            // sa * (ab - x) + sb * x + x * (ab - x) = a[i]
            // x * x - (ab + sb - sa) * x - ab * sa + a[i] = 0
            ld B = (ab + sb - sa);
            ld C = -ab * sa + a[i];

            ld d1 = sqr(B) - 4 * C;
            if (d1 < -eps) ok = false;

            ld dd = sqrtl(fabsl(d1));
            ld x1 = (B - dd) / 2;
            ld x2 = (B + dd) / 2;
            if (rand() & 1) swap(x1, x2);
            if (x1 >= -eps && x1 <= ab + eps) {
                //assert(x2 < 0 || x2 > 1);
                aa[i] = x1;
                bb[i] = ab - aa[i];
            } else {
                if (!(x2 >= -eps && x2 < ab + eps)) {
                    ok = false;
                }
                aa[i] = x2;
                bb[i] = ab - aa[i];
            }
            sa += aa[i];
            sb += bb[i];
        }
        if (ok) break;
    }
    cout << setprecision(7) << fixed;
    forn(i, n) {
        cout << fabs(aa[i]) << " ";
    }
    cout << "\n";
    forn(i, n) {
        cout << fabs(bb[i]) << " ";
    }
    cout << "\n";

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