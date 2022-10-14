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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 18, G = 3;
#define double long double

int main () {
    owo;
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (d >= r1 + r2) {
        cout << 0 << '\n';
        return 0;
    }
    {
        vector <double> a = {r1, r2, d};
        sort(all(a));
        if (a[0] + a[1] < a[2] || abs(a[0] + a[1] - a[2]) < 1e-8) {
            cout << fixed << setprecision(10) << min(r1, r2) * min(r1, r2) * acos(-1) << '\n';
            return 0;
        }
    }
    double ans = 0;
    {
        double cost = (r1 * r1 + d * d - r2 * r2) / 2 / r1 / d;
        double t = acos(cost) * 2;
        ans += r1 * r1 * t / 2 - r1 * r1 * sin(t) / 2;
    }
    swap(r1, r2);
    {
        double cost = (r1 * r1 + d * d - r2 * r2) / 2 / r1 / d;
        double t = acos(cost) * 2;
        ans += r1 * r1 * t / 2 - r1 * r1 * sin(t) / 2;
    }
    cout << fixed << setprecision(10) << ans << endl;
}