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
const int mod = 998244353, N = 300005;

void solve () {
    int n;
    cin >> n;
    vector <int> c(4);
    for (int i = 0; i < 4; ++i)
        cin >> c[i];
    vector <string> s(4);
    for (int i = 0; i < 4; ++i)
        cin >> s[i], s[i] += "...";
    n += 3;
    int now = 0;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 4; ++j) if (s[j][i] == '*') {
        now |= 1 << (i * 4 + j);
    }
    vector <int> pre(1 << 12, 1 << 30);
    pre[now] = 0;
    map <int, int> m1;
    vector <pii> pos = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {0, 2}, {1, 2}, {2, 2}, {0, 3}, {1, 3}, {0, 4}};
    for (int s = 1; s < 1 << 10; ++s) {
        vector <pii> v;
        int msk = 0, sum = 0;
        for (int i = 0; i < 10; ++i) if (s >> i & 1) {
            for (int j = pos[i].X; j < pos[i].X + pos[i].Y; ++j) for (int ii = 0; ii < pos[i].Y; ++ii) {
                msk |= 1 << (ii * 4 + j);
            }
            sum += c[pos[i].Y - 1];
        }
        if (!m1.count(msk))
            m1[msk] = sum;
        else
            m1[msk] = min(m1[msk], sum);
    }
    for (int i = 3; i < n; ++i) {
        int add = 0;
        vector <int> dp(1 << 12, 1 << 30);
        for (int j = 0; j < 4; ++j) if (s[j][i] == '*')
            add |= 1 << j;
        for (int j = 0; j < 1 << 12; ++j) if (pre[j] <= 1000000) {
            int cur = j | (add << 12);
            for (auto [msk, cost] : m1) {
                int nxt = cur & (~msk);
                if (nxt & 15)
                    continue;
                dp[nxt >> 4] = min(dp[nxt >> 4], pre[j] + cost);
            }
            if (cur & 15)
                continue;
            dp[cur >> 4] = min(dp[cur >> 4], pre[j]);
        }
        pre = dp;
    }
    cout << pre[0] << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}