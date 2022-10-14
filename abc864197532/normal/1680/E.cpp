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
const int mod = 998244353, N = 100005, logN = 20, K = 111, M = 4e7, C = 350;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    while (s[0].back() == '.' && s[1].back() == '.') s[0].pop_back(), s[1].pop_back(), n--;
    int st = 0;
    while (s[0][st] == '.' && s[1][st] == '.') st++;
    vv <int> dp(n, 2, 1 << 29);
    if (s[0][st] == '*') dp[st][0] = (s[1][st] == '*');
    if (s[1][st] == '*') dp[st][1] = (s[0][st] == '*');
    for (int i = st + 1; i < n; ++i) {
      int x = s[0][i] == '*', y = s[1][i] == '*';
      if ((x | 1) >= y) dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1 + y);
      if ((x | 1) <= y) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1 + (x | 1));
      if ((y | 1) >= x) dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1 + x);
      if ((y | 1) <= x) dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1 + (y | 1));
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  }
}