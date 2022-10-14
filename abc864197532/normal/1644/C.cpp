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
const int mod = 998244353, N = 2005, logN = 18, K = 1 << 8;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector <lli> ans(n + 1, -1ll << 60);
        for (int i = 0; i < n; ++i) {
            lli sum = 0;
            for (int j = i; j < n; ++j) {
                sum += a[j];
                ans[j - i + 1] = max(ans[j - i + 1], sum);
            }
        }
        for (int i = n - 1; ~i; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        for (int i = 1; i <= n; ++i)
            ans[i] += 1ll * x * i;
        for (int i = 1; i <= n; ++i) {
            ans[i] = max(ans[i], ans[i - 1]);
        }
        for (int i = 0; i <= n; ++i)
            ans[i] = max(ans[i], 0ll);
        printv(all(ans));
    }
}