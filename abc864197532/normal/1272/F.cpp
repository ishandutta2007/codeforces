#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
string s, t;
int dp[201][201][402], n, m;
tuple <int, int, int, char> back[201][201][402];

int solve(int i, int j, int bal) {
  if (i < 0 or j < 0 or bal < 0 or bal > 401) return 1 << 20;
  if (dp[i][j][bal] < (1 << 20)) return dp[i][j][bal];
  int x = i - (i > 0 and s[i-1] == '('), y = j - (j > 0 and t[j-1] == '(');
  if (dp[i][j][bal] > solve(x, y, bal - 1) + 1) {
    dp[i][j][bal] = solve(x, y, bal - 1) + 1;
    back[i][j][bal] = make_tuple(x, y, bal - 1, '(');
  }
  x = i - (i > 0 and s[i-1] == ')'), y = j - (j > 0 and t[j-1] == ')');
  if (dp[i][j][bal] > solve(x, y, bal + 1) + 1) {
    dp[i][j][bal] = solve(x, y, bal + 1) + 1;
    back[i][j][bal] = make_tuple(x, y, bal + 1, ')');
  }
  return dp[i][j][bal];
}


int main () {
  cin >> s >> t;
  n = s.length(), m = t.length();
  fop (i,0,n+1) fop (j,0,m+1) fop (k,0,402) dp[i][j][k] = 1 << 20;
  dp[0][0][0] = 0;
  solve(n, m, 0);
  string ans = "";
  int x = n, y = m, b = 0;
  char c;
  do {
    tie(x, y, b, c) = back[x][y][b];
    ans += c;
  } while (x > 0 or y > 0);
  if (ans.length() & 1) ans += '(';
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}