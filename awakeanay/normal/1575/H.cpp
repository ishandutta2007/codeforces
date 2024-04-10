#include <iostream>
#include <vector>

#define int long long
using namespace std;

const int MAX = 505;

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

vector<vector<int> > aut;
void compute_automaton(string s) {
  s += '#';
  int n = s.size();
  vector<int> pi = prefix_function(s);
  aut.assign(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 2; c++) {
      int j = i;
      while (j > 0 && '0' + c != s[j])
        j = pi[j-1];
      if ('0' + c == s[j])
        j++;
      aut[i][c] = j;
    }
  }
}

int dp[2][MAX][MAX];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::string a, b;
  std::cin >> a >> b;

  compute_automaton(b);

  //dp[i][j][k] = minimum changes to make from character i, in a if exactly
  //k appearances needed and current state of prefix function is j
  
  /*
  for(int i = 0; i <= m; i++)
    std::cout << aut[i][0] << " " << aut[i][1] << std::endl;
    */

  int mx = n-m+1;
  for(int j = 0; j <= m; j++) {
    for(int k = 0; k <= mx; k++) {
      int x = aut[j][0], y = aut[j][1];
      int cur = a[n-1]-'0';
      int ct[2];
      ct[0] = x == m;
      ct[1] = y == m;
      if(ct[cur] == k)
        dp[(n-1)%2][j][k] = 0;
      else if(ct[!cur] == k)
        dp[(n-1)%2][j][k] = 1;
      else
        dp[(n-1)%2][j][k] = MAX;
    }
  }

  for(int i = n-2; i >= 0; i--) {
    for(int j = 0; j <= m; j++) {
      int nt[2];
      nt[0] = aut[j][0];
      nt[1] = aut[j][1];

      int cur = a[i]-'0';
      int ct[2];
      ct[0] = nt[0] == m;
      ct[1] = nt[1] == m;

      //std::cout << i << " " << j << " " << ct[cur] << " " << ct[!cur] << " " << cur << std::endl;

      for(int k = 0; k <= mx; k++) {
        if(k == 0) {
          dp[i%2][j][k] = MAX;
          if(ct[cur] != 1)
            dp[i%2][j][k] = std::min(dp[i%2][j][k], dp[(i+1)%2][nt[cur]][0]);
          if(ct[!cur] != 1)
            dp[i%2][j][k] = std::min(dp[i%2][j][k], dp[(i+1)%2][nt[!cur]][0] + 1);
        }
        else {
          dp[i%2][j][k] = std::min(dp[(i+1)%2][nt[cur]][k-ct[cur]], dp[(i+1)%2][nt[!cur]][k-ct[!cur]] + 1);
        }
        //std::cout << i << " " << j << " " << k << " " << dp[i][j][k] << std::endl;
      }
    }
  }

  for(int i = 0; i <= mx; i++) {
    int cur = dp[0][0][i];
    if(cur >= MAX)
      std::cout << -1 << " ";
    else
      std::cout << cur << " ";
  }
  std::cout << std::endl;

  return 0;
}