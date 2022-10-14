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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 111, M = 1000006, INF = 1e9 + 87;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 1 << 30;
    // dis = 1
    for (int i = 0; i + 1 < n; ++i) {
        int x = a[i], y = a[i + 1];
        if (x > y)
            swap(x, y);
        if (x + x <= y)
            ans = min(ans, x + (y - x - x + 1) / 2);
        else
            ans = min(ans, (x + y + 2) / 3);
    }
    // dis = 2
    for (int i = 0; i + 2 < n; ++i) {
        int x = a[i], y = a[i + 2];
        if (x > y)
            swap(x, y);
        ans = min(ans, 1 + x / 2 + y / 2);
        ans = min(ans, (x + 1) / 2 + (y + 1) / 2);
    }
    // else
    sort(all(a));
    ans = min(ans, (a[0] + 1 >> 1) + (a[1] + 1 >> 1));
    cout << ans << '\n';
}