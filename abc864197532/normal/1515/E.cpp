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
const int N = 405, logN = 20, K = 111;

int mod;

lli dp[N][N];

lli add(lli &a, lli b) {
    b %= mod;
    a += b;
    if (a >= mod) a -= mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    dp[1][1] = 1;
    for (int i = 1; i < n; ++i) for (int j = 1; j <= i; ++j) {
        add(dp[i + 1][j + 1], dp[i][j] * (j + 1));
        add(dp[i + 1][j], dp[i][j] * (j * 2));
        add(dp[i + 2][j], dp[i][j] * (j * 2));
        add(dp[i + 2][j - 1], dp[i][j] * (j * 2 - 2));
        add(dp[i + 3][j - 1], dp[i][j] * (j - 1));
    }
    cout << dp[n][1] << endl;
}