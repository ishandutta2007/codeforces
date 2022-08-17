#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000000007;

std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
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

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::string p;
  std::cin >> p;
  
  std::vector<int> open(n, 0), close(n, 0);
  int ans = 1;

  std::vector<int> poss(n+1, 0);
  int k = p.size();

  std::vector<int> pi = prefix_function(p);
  int id = k-1;
  while(pi[id] != 0) {
    poss[pi[id]] = 1;
    id = pi[id]-1;
  }

  int last = -1;
  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    x--;
    open[x]++;
    close[x+k-1]++;
    if(i && 0 < k-x+last && k-x+last <= n) ans *= poss[k-x+last];
    last = x;
  }

  int cur = 0;
  for(int i = 0; i < n; i++) {
    cur += open[i];
    if(cur == 0)
      ans = (ans*26)%MOD;
    cur -= close[i];
  }

  std::cout << ans << std::endl;

  return 0;
}