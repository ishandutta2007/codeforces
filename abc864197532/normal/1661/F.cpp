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
const int mod = 1e9 + 7, N = 1000005, logN = 20, K = 31;

int main () {
    owo;
    int n;
    lli bound;
    cin >> n;
    vector <int> a(n);
    int pre = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i] = x - pre;
        pre = x;
    }
    auto f = [&](int d, int t) {
        t++;
        int m = d / t, r = d % t;
        return 1ll * m * m * (t - r) + 1ll * (m + 1) * (m + 1) * r;
    };
    auto ask = [&](lli x) {
        // cost >= x delete
        // return pair(dis, put);
        lli ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            // bs
            int l = -1, r = a[i] + 1;
            while (r - l > 1) {
                int m = l + r >> 1;
                if (f(a[i], m) - f(a[i], m + 1) >= x)
                    l = m;
                else
                    r = m;
            }
            // split point: l
            ans2 += r;
            ans1 += f(a[i], r);
        }
        return mp(ans1, ans2);
    };
    cin >> bound;
    lli l = 1, r = 1ll << 60;
    while (r - l > 1) {
        lli m = l + r >> 1;
        if (ask(m).X <= bound)
            l = m;
        else
            r = m;
    }
    auto res = ask(r);
    test(res);
    cout << (res.X - bound + l - 1) / l + res.Y << '\n';
}