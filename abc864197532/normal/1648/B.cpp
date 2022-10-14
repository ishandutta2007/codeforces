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
const int mod = 1e9 + 7, N = 1000001, logN = 20, K = 111, C = 7;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, C;
        cin >> n >> C;
        vector <bool> vis(C + 1, false);
        vector <int> pre(C + 1, 0);
        for (int i = 0, x; i < n; ++i)
            cin >> x, vis[x] = true, pre[x] = 1;
        for (int i = 1; i <= C; ++i)
            pre[i] += pre[i - 1];
        // x = yz + r, 0 < r < y, z not in S
        bool ans = true;
        for (int z = 1; z <= C; ++z) if (!vis[z]) {
            for (int y = 1; y * z <= C; ++y) if (vis[y]) {
                int l = y * z - 1, r = min(y * (z + 1), C + 1) - 1;
                if (pre[r] - pre[l] > 0)
                    ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}