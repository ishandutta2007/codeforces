/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 2520, logN = 20;
const double bound = 1e12, eps = 1e-8;

struct Pt {
	double x, y;
	Pt (double _x = 0, double _y = 0) : x(_x), y(_y) {}
	Pt operator + (const Pt &other) {
		return Pt(x + other.x, y + other.y);
	}
	Pt operator - (const Pt &other) {
		return Pt(x - other.x, y - other.y);
	}
	Pt operator * (const double &k) {
		return Pt(x * k, y * k);
	}
	Pt operator / (const double &k) {
		return Pt(x / k, y / k);
	}
	double operator * (const Pt &other) { // dot
		return x * other.x + y * other.y;
	}
	double operator ^ (const Pt &other) { // cross
		return x * other.y - y * other.x;
	}
    bool operator < (const Pt &other) {
        if (abs(x - other.x) <= eps) return y < other.y;
        return x < other.x;
    }
    bool operator == (const Pt &other) {
        return abs(x - other.x) <= eps && abs(y - other.y) <= eps;
    }
	double dis (const Pt &o) {
	    return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
	}
};

double intersect_rate(Pt a, Pt b, Pt c, Pt d) {
    double t = ((c - a) ^ (d - c)) / ((b - a) ^ (d - c));
    return t;
}

bool in(double t) {
    return (0 < t && t < 1) || abs(t) <= eps || abs(t - 1) <= eps;
}

vector <Pt> poly;

bool chk(Pt tmp) {
    int n = poly.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        if (poly[i] == tmp) return 1;
        int j = i + 1;
        if (j == n) j = 0;
        {
            Pt a = tmp - poly[i], b = tmp - poly[j];
            if ((a ^ b) == 0 && (a * b) < 0) return 1;
        }
        double p = intersect_rate(poly[i], poly[j], tmp, tmp + Pt(1, bound));
        double q = intersect_rate(tmp, tmp + Pt(1, bound), poly[i], poly[j]);
        if (0 <= p && p <= 1 && 0 <= q && q <= 1) {
            ans ^= 1;
        }
    }
    return ans;
}

double get() {
    string s;
    cin >> s;
    double now = 0;
    int num = 0;
    bool is = false, flag = false;
    for (char c : s) {
        if (c == '-') flag = true;
        else if (c == '.') is = true;
        else {
            now = now * 10 + c - '0';
            if (is) num++;
        }
    }
    while (num--) now /= 10;
    if (flag) now = -now;
    return now;
}

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    poly.resize(n);
    for (int i = 0; i < n; ++i) {
        poly[i].x = get(), poly[i].y = get();
    }
    while (q--) {
        Pt a, b;
        a.x = get(), a.y = get(), b.x = get(), b.y = get();
        vector <Pt> inter;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            if (j == n) j = 0;
            double p = intersect_rate(poly[i], poly[j], a, b);
            if (in(p)) {
                inter.pb(poly[i] + (poly[j] - poly[i]) * p);
            }
        }
        sort(all(inter));
        inter.resize(unique(all(inter)) - inter.begin());
        double ans = 0;
        for (int i = 1; i < inter.size(); ++i) {
            if (chk((inter[i - 1] + inter[i]) / 2)) {
                ans += inter[i - 1].dis(inter[i]);
            }
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}