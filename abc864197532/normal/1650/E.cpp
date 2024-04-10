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
const int mod = 998244353, N = 401, logN = 20, K = 111, C = 7;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        auto solve = [&](int len, int p) {
            vector <int> b = a;
            b.erase(b.begin() + p);
            bool ok = false;
            for (int i = 1; i < n; ++i) {
                if (b[i] - b[i - 1] - 1 < len)
                    return false;
                if (b[i] - b[i - 1] >= (len + 1) * 2)
                    ok = true;
            }
            if (d - b.back() - 1 >= len)
                ok = true;
            return ok;
        };
        auto ask = [&](int len) {
            int p = -1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] - a[i - 1] - 1 < len) {
                    p = i;
                    break;
                }
            }
            if (p == -1)
                return true;
            if (solve(len, p))
                return true;
            if (p && solve(len, p - 1))
                return true;
            return false;
        };
        int l = 0, r = d + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (ask(m))
                l = m;
            else
                r = m;
        }
        cout << l << '\n';
    }
}