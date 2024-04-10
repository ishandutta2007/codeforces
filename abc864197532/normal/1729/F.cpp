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
const int mod = 998244353, N = 1 << 19;

void solve() {
    int n, m, q;
    string s;
    cin >> s >> m >> q;
    n = s.length();
    vector <int> fr(9, -1), fr2(9, -1), pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = (pre[i] * 10 + s[i] - '0') % 9;
    }
    auto query = [&](int l, int r) {
        return (pre[r] - pre[l] + 9) % 9;
    };
    for (int i = 0; i + m <= n; ++i) {
        int x = query(i, i + m);
        if (fr[x] == -1) {
            fr[x] = i;
        } else if (fr2[x] == -1)
            fr2[x] = i;
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k, --l;
        int v = query(l, r);
        pii ans = mp(n, n);
        for (int i = 0; i < 9; ++i) if (fr[i] != -1) {
            int need = (k - v * i % 9 + 9) % 9;
            if (i != need) {
                if (fr[need] != -1)
                    ans = min(ans, mp(fr[i], fr[need]));
            } else {
                if (fr2[need] != -1)
                    ans = min(ans, mp(fr[i], fr2[need]));
            }
        }
        if (ans.X == n)
            cout << "-1 -1\n";
        else
            cout << ans.X + 1 << ' ' << ans.Y + 1 << '\n';
    }

}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}