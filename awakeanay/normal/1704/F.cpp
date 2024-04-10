#include <iostream>
#include <vector>

#define int long long

int mex(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> poss(n+1, 0);
  for(int j : arr)
    if(j <= n)
      poss[j] = 1;
  for (int i = 0; i <= n; i++)
    if(!poss[i])
      return i;
}

const int MAXN = 800;
int dp[MAXN];

int solve(int x) {
  if(x < MAXN)
    return dp[x];
  x %= 136;
  while(x+136 < MAXN)
    x += 136;
  return dp[x];
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  dp[0] = 0;
  dp[1] = 1;
  int max = 0;
  bool check = 1;
  for(int i = 1; i < MAXN; i++) {
    std::vector<int> next;
    for(int j = 0; j < i; j++) {
      int x = (j == 0 ? dp[j] : dp[j-1]);
      int y = (j == i-1 ? dp[0] : dp[i-2-j]);
      next.push_back(x^y);
    }
    dp[i] = mex(next);
    if(i >= 500)
      check &= dp[i] == dp[i-136];
    //max = std::max(max, dp[i]);
    //std::cout << dp[i] << " ";
  }
  //std::cout << check << std::endl;
  //std::cout << max;
  //std::cout << std::endl;

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int tot = 0;
    int sub = 0;
    int change = 0;
    std::string s;
    std::cin >> s;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'R') {
        sub++;
      }
      else {
        sub--;
      }
      if(i > 0 && s[i] != s[i-1]) {
        tot++;
      }
      else {
        change ^= solve(tot);
        tot = 0;
      }
    }
    change ^= solve(tot);
    //std::cout << change << std::endl;

    if(change) {
      std::cout << (sub < 0 ? "Bob" : "Alice") << std::endl;
    }
    else {
      std::cout << (sub > 0 ? "Alice" : "Bob") << std::endl;
    }
  }


  return 0;
}