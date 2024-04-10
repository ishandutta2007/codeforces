#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const double eps = 1e-9;

typedef pair<double, double> pdd;

pdd operator-(const pdd &a, const pdd &b) { return pdd(a.X - b.X, a.Y - b.Y); }
double dot(const pdd &a, const pdd &b) { return a.X * b.X + a.Y * b.Y; }
double abs2(const pdd &a) { return dot(a ,a); }
int sign(const double &a) { return fabs(a) < eps ? 0 : a > 0 ? 1 : -1; }

struct Poly {
    double x, y, a;
    Poly(double _x = 0, double _y = 0, double _a = 0): x(_x), y(_y), a(_a) {}
    bool operator<(const Poly &p) const {
        if (sign(x - p.x) != 0) return sign(x - p.x) < 0;
        if (sign(y - p.y) != 0) return sign(y - p.y) < 0;
        return sign(a - p.a) < 0;
    }
    bool operator==(const Poly &p) const {
        return !(*this < p) && !(p < *this);
    }
    Poly operator+(const double &dx) const {
        Poly rt(*this);
        rt.x += dx;
        return rt;
    }
    Poly operator*(const double &dy) const {
        Poly rt(*this);
        rt.y += dy;
        return rt;
    }
    Poly operator+(const Poly &p) const {
        Poly rt;
        rt.a = a + p.a;
        rt.x = (x * a + p.x * p.a) / rt.a;
        rt.y = (y * a + p.y * p.a) / rt.a;
        return rt;
    }
};

vector<Poly> mass[18];
Poly trapezoid[19];

string solve(int n, double x, double y) {
    if (n == 0) return "";
    if (n == 1) return "()";
    for (int j = 1; j <= n; ++j)
        for (auto p : mass[j - 1])
            for (auto q : mass[n - j]) {
                Poly nw = trapezoid[j] + (p * 1. + 1.) + (q + j * 2.);
                if (sign(abs2(pdd(x, y) - pdd(nw.x, nw.y))) == 0)
                    return "(" + solve(j - 1, p.x, p.y) + ")" + solve(n - j, q.x, q.y);
            }
    assert(0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n, n /= 2;
    for (int i = 1; i <= n; ++i) {
        Poly upper = Poly(2. * i / 3, 2. / 3, i - 1);
        Poly lower = Poly((4. * i - 1) / 3, 1. / 3, i);
        trapezoid[i] = upper + lower;
    }
    mass[0].pb(trapezoid[0]);
    mass[1].pb(trapezoid[1]);
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (auto p : mass[j - 1])
                for (auto q : mass[i - j])
                    mass[i].pb(trapezoid[j] + (p * 1. + 1.) + (q + j * 2.));
        }
        sort(ALL(mass[i])), mass[i].resize(unique(ALL(mass[i])) - mass[i].begin());
    }
    double x, y;
    cin >> x >> y;
    cout << solve(n, x, y) << "\n";
}