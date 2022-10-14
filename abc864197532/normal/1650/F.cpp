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
const int mod = 998244353, N = 401, logN = 20, K = 111, C = 7;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector <vector <array <int, 3>>> item(n);
        for (int i = 0, a, b, c; i < m; ++i) {
            cin >> a >> b >> c, --a;
            item[a].pb({b, c, i});
        }
        bool fail = false;
        vector <int> ord;
        lli now_t = 0;
        for (int i = 0; i < n; ++i) {
            int m = item[i].size();
            vv <lli> dp(m + 1, 201, 1ll << 60);
            dp[0][0] = 0;
            int t = 1;
            for (auto &b : item[i]) {
                dp[t] = dp[t - 1];
                for (int j = 200 - b[1]; ~j; --j) {
                    if (dp[t][j + b[1]] > dp[t - 1][j] + b[0]) {
                        dp[t][j + b[1]] = dp[t - 1][j] + b[0];
                    }
                }
                t++;
            }
            pair <lli, int> mn = mp(dp.back()[100], 100);
            for (int i = 101; i <= 200; ++i)
                mn = min(mn, mp(dp.back()[i], i));
            if (now_t + mn.X > a[i]) {
                fail = true;
                break;
            }
            now_t += mn.X;
            int now = mn.Y;
            for (int j = m - 1; ~j; --j) {
                if (now >= item[i][j][1] && dp[j + 1][now] == dp[j][now - item[i][j][1]] + item[i][j][0])
                    now -= item[i][j][1], ord.pb(item[i][j][2] + 1);
            }
        }
        if (fail) {
            cout << -1 << endl;
            continue;
        }
        cout << ord.size() << endl;
        printv(all(ord));
    }
}