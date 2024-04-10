#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int INF = 400000;

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
  s += '#';
  int n = s.size();
  vector<int> pi = prefix_function(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pi[i-1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string a, s, t;
  std::cin >> a >> s >> t;

  int n = a.length();
  int x = s.length();
  int y = t.length();

  std::vector<std::vector<int> > auts, autt;
  compute_automaton(s, auts);
  compute_automaton(t, autt);

  int dp[n+1][x+1][y+1];
  for(int i = 0; i <= x; i++)
    for(int j = 0; j <= y; j++)
      dp[0][i][j] = (i+j == 0 ? 0 : -INF);

  int ans = -INF;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= x; j++)
      for(int k = 0; k <= y; k++)
        dp[i][j][k] = -INF;

    char c = a[i-1];
    for(int j = 0; j <= x; j++) {
      for(int k = 0; k <= y; k++) {
        for(int l = 0; l < 26; l++) {
          if(c-'a' != l && c != '*')
            continue;

          int p = auts[j][l];
          int q = autt[k][l];

          dp[i][p][q] = std::max(dp[i][p][q], dp[i-1][j][k] + (p == x) - (q == y));
          if(i == n) {
            ans = std::max(ans, dp[i][p][q]);
          }
        }
      }
    }

  }

  std::cout << ans << std::endl;

  return 0;
}