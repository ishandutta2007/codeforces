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
const int mod = 998244353, N = 1e6 + 5, logN = 20, K = 111, C = 1e9;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <lli> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        // both
        lli ans = 1ll << 60;
        for (int t : {0, 1}) {
            ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
            // left
            {
                lli A = 1ll << 60, B = 1ll << 60;
                for (int i = 0; i + 1 < n; ++i) {
                    A = min(A, abs(a[n - 1] - b[i]));
                    B = min(B, abs(b[n - 1] - a[i]));
                }
                ans = min(ans, abs(a[0] - b[0]) + A + B);
            }
            // right
            {
                lli A = 1ll << 60, B = 1ll << 60;
                for (int i = 1; i < n; ++i) {
                    A = min(A, abs(a[0] - b[i]));
                    B = min(B, abs(b[0] - a[i]));
                }
                ans = min(ans, abs(a[n - 1] - b[n - 1]) + A + B);
            }
            // none
            {
                lli A = 1ll << 60, B = 1ll << 60, C = 1ll << 60, D = 1ll << 60;
                for (int i = 1; i + 1 < n; ++i) {
                    A = min(A, abs(a[0] - b[i]));
                    C = min(C, abs(a[n - 1] - b[i]));
                    B = min(B, abs(b[0] - a[i]));
                    D = min(D, abs(b[n - 1] - a[i]));
                }
                ans = min(ans, A + B + C + D);
            }
            reverse(all(b));
        }
        cout << ans << '\n';
    }
}