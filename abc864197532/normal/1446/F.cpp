#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200007, logN = 20, C = 15;
const double eps = 1e-8, PI = acos(0) * 2;

struct Pt {
    int x, y;
    Pt (int _x, int _y) : x(_x), y(_y) {}
    int operator * (const Pt &o) {
        return x * o.x + y * o.y;
    }
    int operator ^ (const Pt &o) {
        return x * o.y - y * o.x;
    }
    Pt operator + (const Pt &o) {
        return Pt(x + o.x, y + o.y);
    }
    Pt operator - (const Pt &o) {
        return Pt(x - o.x, y - o.y);
    }
};

bool lesss(double a, double b) {
    return a - eps < b;
}

bool equ(double a, double b) {
    return abs(a - b) < eps;
}

struct BIT {
    int val[N];
    BIT () {fill(val, val + N, 0);}
    void add(int p, int v) {
        for (p += 3; p < N; p += p & (-p))
            val[p] += v;
    }
    int query(int p) {
        int ans = 0;
        for (p += 3; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
};

int main () {
    owo;
    int n;
    lli k;
    cin >> n >> k;
    vector <Pt> a;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        a.pb(Pt(x, y));
    }
    auto chg = [&](double x) {
        while (lesss(x, 0))
            x += PI * 2;
        while (lesss(PI * 2, x))
            x -= PI * 2;
        return x;
    };
    auto ask = [&](double r) {
        vector <double> x;
        int cnt = 0;
        vector <pair <double, double>> interval;
        for (int i = 0; i < n; ++i) {
            double dis = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
            if (lesss(dis, r)) {
                cnt++;
                continue;
            }
            double c = atan2(a[i].y, a[i].x);
            double d = acos(r / dis);
            double a = chg(c + d), b = chg(c - d);
            if (a > b)
                swap(a, b);
            x.pb(a), x.pb(b);
            interval.eb(a, b);
        }
        sort(all(x)), x.resize(unique(all(x)) - x.begin());
        vector <pair <int, int>> range;
        for (auto [l, r] : interval) {
            int idl = lower_bound(all(x), l) - x.begin();
            int idr = lower_bound(all(x), r) - x.begin();
            range.eb(idr, idl);
        }
        sort(all(range));
        BIT bit;
        lli ans = 0;
        for (auto [r, l] : range) {
            ans += bit.query(l);
            bit.add(l, 1);
            bit.add(r, -1);
        }
        return 1ll * n * (n - 1) / 2 - ans;
    };
    double l = 0, r = 2e4;
    for (int t = 0; t < 50; ++t) {
        double m = (l + r) / 2;
        if (ask(m) < k)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(15) << l << endl;
}