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
const int mod = 998244353, N = 200020, logN = 20, M = 6e6;

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
    if (i < 0)
        i += mod;
}

int dp[201][3], pre[201][3];

int main () {
    owo;
    int n;
    cin >> n;
    // 0 <, 1 = , 2 >
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        for (int j = 0; j <= 200; ++j) for (int k = 0; k < 3; ++k)
            dp[j][k] = 0;
        if (i) {
            for (int x = 1; x <= 200; ++x) for (int j = 0; j < 3; ++j) {
                add(pre[x][j], pre[x - 1][j]);
            }
        }
        if (i > 1) {
            for (int j = 1; j <= 200; ++j) if (x == -1 || x == j) {
                // 0 -> 0, 1
                // 1 -> 0, 1, 2
                // 2 -> 0, 1, 2
                for (int ii = 0; ii < 3; ++ii) for (int jj = 0; jj < 3; ++jj) if (!(ii == 0 && jj == 2)) {
                    if (jj == 2) {
                        add(dp[j][jj], pre[200][ii]);
                        add(dp[j][jj], -pre[j][ii]);
                    } else if (jj == 1) {
                        add(dp[j][jj], pre[j][ii]);
                        add(dp[j][jj], -pre[j - 1][ii]);
                    } else {
                        add(dp[j][jj], pre[j - 1][ii]);
                    }
                }
            }
        } else if (i) {
            for (int j = 1; j <= 200; ++j) if (x == -1 || x == j) {
                dp[j][0] = pre[j - 1][0];
                dp[j][1] = pre[j][0] - pre[j - 1][0];
            }
        } else {
            for (int j = 1; j <= 200; ++j) if (x == -1 || x == j)
                dp[j][0] = 1;
        }
        for (int j = 0; j <= 200; ++j) for (int k = 0; k < 3; ++k)
            pre[j][k] = dp[j][k];
    }
    int ans = 0;
    for (int j = 1; j <= 200; ++j)
        add(ans, pre[j][1]), add(ans, pre[j][2]);
    cout << ans << endl;
}