#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

struct part
{
  int l, r;
  inline bool operator<(part b) {
    return l+r < b.l + b.r;
  }
};

signed main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int ans = 0;

  part list[m];
  std::vector<int> preA(n, 0), preB(n, 0);
  for(int i = 0; i < m; i++) {
    std::cin >> list[i].l >> list[i].r;
    list[i].l--; list[i].r--;
    for(int j = list[i].l; j < n; j++) {
      preB[j] += std::min(j, list[i].r)-list[i].l+1;
    }
  }

  std::sort(list, list+m);
  int cur = 0;
  for(int l = 0; l <= 2*(n-k); l++) {
    while(cur < m && l+k-1 >= list[cur].l + list[cur].r) {
      for(int j = list[cur].l; j < n; j++) {
        preB[j] -= std::min(j, list[cur].r)-list[cur].l+1;
        preA[j] += std::min(j, list[cur].r)-list[cur].l+1;
      } 
      cur++;
    }

    //for(int i = 0; i < n; i++) {
    //  std::cout << preA[i] << " ";
    //}
    //std::cout << std::endl;
    //for(int i = 0; i < n; i++) {
    //  std::cout << preB[i] << " ";
    //}
    for(int i = 0; 2*i <= l; i++) {
      int j = l-i;
      if(j+k-1 >= n)
        continue;
      //std::cout << i+k-1 << " " << j+k-1 << " " << l << std::endl;
      //std::cout << preA[i+k-1] << " " << preB[j+k-1]<< std::endl;
      ans = std::max(ans, preA[i+k-1]-(i ? preA[i-1] : 0ll) + preB[j+k-1]-(j ? preB[j-1] : 0ll));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}