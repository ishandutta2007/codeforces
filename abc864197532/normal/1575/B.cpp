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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100001, logN = 20;

int main () {
    owo;
    double PI = asin(1) * 2;
    int n, k;
    cin >> n >> k;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].X >> a[i].Y;
    }
    vector <double> tmp(n), dis(n);
    for (int i = 0; i < n; ++i)
        tmp[i] = atan2(a[i].Y, a[i].X), dis[i] = (double)sqrt(1ll * a[i].X * a[i].X + 1ll * a[i].Y * a[i].Y);
    auto ask = [&](double r) {
        int ans = 0;
        map <lli, int> m1;
        auto add = [&](double x, int v) {
            m1[(long long)(x * 100000)] += v;
        };
        for (int i = 0; i < n; ++i) {
            double x = dis[i] / r / 2;
            if (x <= -1) {
                ans++;
                continue;
            }
            double l = asin(x), r = PI - l;
            l -= tmp[i], r -= tmp[i];
            if (l <= 0 && 0 <= r) {
                add(0, 1);
                add(r, -1);
                add(l + PI * 2, 1);
                add(r + PI * 2, -1);
            } else if (0 < l) {
                add(l, 1);
                add(r, -1);
            } else {
                add(l + PI * 2, 1);
                add(r + PI * 2, -1);
            }
        }
        int ans2 = 0, res = 0;
        for (auto A : m1) {
            res += A.Y;
            ans2 = max(ans2, res);
        }
        return ans + ans2 >= k;
    };
    double l = 0, r = 3e5;
    int t = 33;
    while (t--) {
        double m = (l + r) / 2;
        if (ask(m))
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(10) << l << endl;
}