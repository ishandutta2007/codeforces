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
const int mod = 1e9 + 7, N = 1002, logN = 20, K = 600, M = 1e9 + 1;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        lli x;
        cin >> n >> x;
        vector <lli> pre(n + 1);
        for (int i = 0, x; i < n; ++i)
            cin >> x, pre[i + 1] = pre[i] + x;
        // pre[j] - pre[i] + x >= 0
        // pre[j] >= pre[i] - x
        vector <int> p(n + 1, 0);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            return pre[i] < pre[j];
        });
        set <int> s;
        s.insert(n + 1);
        int l = -1, len = 0;
        for (int i = 0, j = 0; i <= n; ++i) {
            while (j <= n && pre[p[j]] < pre[p[i]] - x) {
                s.insert(p[j++]);
            }
            auto it = s.lower_bound(p[i]);
            if (len < *it - p[i] - 1) {
                len = *it - p[i] - 1;
                l = p[i];
            }
        }
        if (l == -1)
            cout << l << endl;
        else
            cout << l + 1 << ' ' << l + len << endl;
    }
}