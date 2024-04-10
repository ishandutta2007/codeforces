#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;

int s[MAXN];
int rev[MAXN];
int n, m;

int calc(int k) {
  int a[n];
  int vis[n];
  for(int i = 0; i < n; i++) {
    a[i] = (i+n-k)%n;
    vis[i] = 0;
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(vis[i])
      continue;
    int cur = i;
    int count = 0;
    while(!vis[cur]) {
      count++;
      vis[cur] = 1;
      cur = rev[a[cur]];
    }

    ans += count-1;
  }

  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> m;

    std::vector<int> count(n, 0);
    for(int i = 0; i < n; i++) {
      std::cin >> s[i];
      s[i]--;
      count[(i-s[i]+n)%n]++;
      rev[s[i]] = i;
    }

    std::vector<int> ans;
    for(int i = 0; i < n; i++) {
      if(count[i]*3 >= n) {
        if(calc(i) <= m)
          ans.push_back(i);
      }
    }

    std::cout << ans.size() << " ";
    for(int j : ans)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}