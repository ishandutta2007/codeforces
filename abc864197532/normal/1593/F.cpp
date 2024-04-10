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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1001, logN = 20, K = 15;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        vvvv <bool> dp(n + 1, n + 1, a, b, false);
        dp[0][0][0][0] = true;
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < a; ++j) {
                    for (int k = 0; k < b; ++k) if (dp[t][i][j][k]) {
                        // A
                        dp[t + 1][i][(j * 10 + s[t] - '0') % a][k] = true;
                        // B
                        dp[t + 1][i + 1][j][(k * 10 + s[t] - '0') % b] = true;
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 1; i < n; ++i) if (dp[n][i][0][0]) {
            if (ans == -1 || abs(n - ans * 2) > abs(n - i * 2)) {
                ans = i;
            }
        }
        if (ans == -1) {
            cout << ans << endl;
        } else {
            int i = n, cnt = ans, j = 0, k = 0;
            string ans;
            while (i > 0) {
                char c = ' ';
                for (int ii = 0; ii < a; ++ii) if (dp[i - 1][cnt][ii][k] && (ii * 10 + s[i - 1] - '0') % a == j) {
                    c = 'R';
                    i--, j = ii;
                    break;
                }
                if (c == ' ') {
                    for (int ii = 0; ii < b; ++ii) if (dp[i - 1][cnt - 1][j][ii] && (ii * 10 + s[i - 1] - '0') % b == k) {
                        c = 'B';
                        i--, k = ii, cnt--;
                        break;
                    }
                }
                ans.pb(c);
            }
            reverse(all(ans));
            cout << ans << endl;
        }
    }
}