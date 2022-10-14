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
    int n, k;
    cin >> n >> k;
    vector <lli> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    reverse(all(a));
    vv <lli> lz(n + 1, 2, 0);
    lli pre0 = 0, pre1 = 0, ans = 0;
    for (int i = 0; i + k <= n; ++i) {
        pre0 += lz[i][0], pre1 += lz[i][1];
        lli need = (a[i] - (pre0 * i + pre1) + k - 1) / k;
        if (need <= 0)
            continue;
        ans += need;
        // function: k + i - x
        pre0 -= need, pre1 += (k + i) * need;
        lz[i + k][0] += need, lz[i + k][1] -= (k + i) * need;
    }
    test(ans);
    lli mx = 0;
    for (int i = n - k + 1; i < n; ++i) {
        pre0 += lz[i][0], pre1 += lz[i][1];
        test(i, pre0, pre1);
        lli now = a[i] - (pre0 * i + pre1);
        mx = max(mx, (now + n - i - 1) / (n - i));
    }
    cout << ans + mx << '\n';
}