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
const int mod = 998244353, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

void del(int &i, int j) {
    i -= j;
    if (i < 0)
        i += mod;
}

int main () {
    owo;
    int n, k, len;
    cin >> n >> k >> len;
    vector <int> lst(k, -1);
    vv <int> dp(n, k, 0);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (~x)
            --x;
        if (i) {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < k; ++j)
                add(sum1, dp[i - 1][j]);
            if (i == len - 1) {
                sum2 = 1;
            } else if (i >= len) {
                for (int j = 0; j < k; ++j)
                    add(sum2, dp[i - len][j]);
            }
            for (int j = 0; j < k; ++j) if (x == -1 || x == j) {
                dp[i][j] = sum1;
                if (i - lst[j] >= len) {
                    int tmp = sum2;
                    if (i >= len)
                        del(tmp, dp[i - len][j]);
                    del(dp[i][j], tmp);
                }
            }
        } else {
            for (int j = 0; j < k; ++j) if (x == -1 || x == j)
                dp[i][j] = (len == 1 ? 0 : 1);
        }
        if (x != -1) {
            for (int j = 0; j < k; ++j) if (j != x)
                lst[j] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
        add(ans, dp[n - 1][i]);
    cout << ans << '\n';
}