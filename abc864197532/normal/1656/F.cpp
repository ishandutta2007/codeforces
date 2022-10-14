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
const int mod = 998244353, N = 300005, logN = 20, K = 111;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(all(a));
        auto ask = [&](int t) {
            vector <int> b(n);
            for (int i = 0; i < n; ++i)
                b[i] = a[i], b[i] += t;
            lli ans = 0;
            if (b[0] > 0) {
                for (int i = 1; i < n; ++i)
                    ans += 1ll * b[0] * b[i];
            } else if (b[n - 1] < 0) {
                for (int i = 0; i + 1 < n; ++i)
                    ans += 1ll * b[i] * b[n - 1];
            } else {
                ans += 1ll * b[0] * b[n - 1];
                for (int i = 1; i + 1 < n; ++i) {
                    if (b[i] < 0)
                        ans += 1ll * b[i] * b[n - 1];
                    else
                        ans += 1ll * b[i] * b[0];
                }
            }
            return ans - 1ll * t * t * (n - 1);
        };
        int l = -1 << 20, r = 1 << 20;
        while (r - l > 10) {
            int m1 = (l + l + r) / 3, m2 = (l + r + r) / 3;
            if (ask(m1) > ask(m2))
                r = m2;
            else
                l = m1;
        }
        lli res = -1ll << 60;
        for (int i = l; i < r; ++i)
            res = max(res, ask(i));
        if (ask((-1 << 20) - 1) > res || ask(1 << 20) > res) {
            cout << "INF\n";
        } else {
            cout << res << '\n';
        }
    }
}