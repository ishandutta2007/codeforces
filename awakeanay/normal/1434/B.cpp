#include <iostream>
#include <vector>

#define int long long
#define MAXN 200005

struct node {
  int l, r;
};

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> ans(2*n, -1);
  bool poss = true;

  int rev[n+1];
  node list[2*n+2];
  char a[2*n];
  for(int i = 0; i < 2*n; i++) {
    list[i].r = i+1;
    list[i].l = i-1;
    std::cin >> a[i];

    if(a[i] == '-') {
      int x;
      std::cin >> x;
      rev[x] = i;
    }
  }

  for(int i = 1; i <= n; i++) {
    if(list[rev[i]].l < 0 || a[list[rev[i]].l] == '-') {
      poss = false;
      break;
    }

    ans[list[rev[i]].l] = i;
    list[list[rev[i]].r].l = list[list[rev[i]].l].l;
    int left = list[rev[i]].l;
    if(list[left].l >= 0)
      list[list[left].l].r = list[rev[i]].r;
  }

  if(poss) {
    std::cout << "YES" << std::endl;
    for(int j : ans)
      if(j != -1)
        std::cout << j << " ";
  }
  else 
    std::cout << "NO";

  std::cout << std::endl;

  return 0;
}