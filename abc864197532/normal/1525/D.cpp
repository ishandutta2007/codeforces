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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
const int mod = 998244353, N = 1000001 / 3, logN = 20, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> cost(n + 1, vector <int>(n + 1, 1e9));
    for (int i = 0; i < n; ++i) {
        int res = 0, cur = 0;
        for (int j = i; j < n; ++j) {
            if (a[j]) res -= j, cur++;
            else if (cur) res += j, cur--;
            if (cur == 0) cost[i][j + 1] = min(cost[i][j + 1], res);
        }
    }
    for (int j = n - 1; ~j; --j) {
        int res = 0, cur = 0;
        for (int i = j; ~i; --i) {
            if (a[i]) res += i, cur++;
            else if (cur) res -= i, cur--;
            if (cur == 0) cost[i][j + 1] = min(cost[i][j + 1], res);
        }
    }
    vector <int> dp(n + 1, 1 << 30);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + cost[j][i]);
        }
    }
    cout << dp[n] << endl;
}