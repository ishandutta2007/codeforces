#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 130002;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    int ans = 0, mn = 1 << 30;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ans += count(all(s[i]), '1');
    }
    if (!ans) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < m; ++j) {
        int cnt = (s[i][j] - '0') + (s[i + 1][j] - '0') + (s[i][j + 1] - '0') + (s[i + 1][j + 1] - '0');
        if (cnt == 1)
            mn = min(mn, 1);
        else if (cnt)
            mn = min(mn, cnt - 1);
    }
    cout << ans - mn + 1 << '\n';
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}