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
const int mod = 1e9 + 7, N = 2520, logN = 20, K = 350;

struct Pt {
    long long x, y;
    Pt (long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    Pt operator + (const Pt &other) {
        return Pt(x + other.x, y + other.y);
    }
    Pt operator - (const Pt &other) {
        return Pt(x - other.x, y - other.y);
    }
    Pt operator * (const int &k) {
        return Pt(x * k, y * k);
    }
    long long operator * (const Pt &other) { // dot
        return x * other.x + y * other.y;
    }
    long long operator ^ (const Pt &other) { // cross
        return x * other.y - y * other.x;
    }
    long long len() {
        return x * x + y * y;
    }
};

struct frac {
    lli a, b; // a / b
    frac(lli _a, lli _b) : a(_a), b(_b) {}
    bool operator < (const frac& o) {
        __int128 A = a, B = o.a;
        return A * o.b < B * b;
    }
};

frac get_angle(Pt a, Pt b) {
    lli A = a * b, B = a.len() * b.len();
    bool flag = false;
    if (A < 0) flag = true;
    A *= A;
    lli g = __gcd(A, B);
    A /= g, B /= g;
    if (flag) A = -A;
    A = B - A;
    return frac(A, B);
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <Pt> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        bool f1 = a[i].x < 0 || (a[i].x == 0 && a[i].y < 0);
        bool f2 = a[j].x < 0 || (a[j].x == 0 && a[j].y < 0);
        if (f1 != f2) return f1 < f2;
        return (a[i] ^ a[j]) > 0;
    });
    int nowx = p[0], nowy = p[1];
    frac best = get_angle(a[p[0]], a[p[1]]);
    for (int i = 1; i < n; ++i) {
        int j = (i + 1) % n;
        frac now = get_angle(a[p[i]], a[p[j]]);
        if (now < best) {
            tie(nowx, nowy) = mp(p[i], p[j]);
            best = now;
        }
    }
    cout << nowx + 1 << ' ' << nowy + 1 << endl;
}