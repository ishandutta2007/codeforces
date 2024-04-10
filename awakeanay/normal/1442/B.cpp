#include <iostream>
#define MOD 998244353

struct node
{
  int l, r;
};

void rem(int i, node list[]) {
  list[list[i].l].r = list[i].r;
  list[list[i].r].l = list[i].l;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    node list[n+2];
    int mark[n+2];
    for(int i = 1; i < n+2; i++) {
      mark[i] = true;
      list[i].l = i-1;
      list[i-1].r = i;
    }
    mark[0] = mark[n+1] = false;
    
    int rev[n+2];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      rev[x] = i+1;
    }

    int ans = 1;
    int b[k];
    for(int i = 0; i < k; i++) {
      std::cin >> b[i];
      mark[rev[b[i]]] = false;
    }

    for(int i = 0; i < k; i++) {
      int poss = 0;
      int toR = -1;
      if(mark[list[rev[b[i]]].r]) {
        poss++;
        toR = list[rev[b[i]]].r;
      }
      if(mark[list[rev[b[i]]].l]) {
        poss++;
        toR = list[rev[b[i]]].l;
      }
      if(toR != -1) rem(toR, list);
      mark[rev[b[i]]] = true;
      ans = (ans*poss)%MOD;
    }

    std::cout << ans << std::endl;

  }
  return 0;
}