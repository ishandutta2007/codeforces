#include <iostream>

#define int long long

int inter(int x, int y, int a, int b) {
  return std::max(0ll, std::min(y-a, b-x));
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int W, H;
    std::cin >> W >> H;
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int w, h;
    std::cin >> w >> h;

    bool bw = x2-x1+w > W;
    bool bh = y2-y1+h > H;

    if(bw && bh)
      std::cout << -1 << std::endl;
    else {
      int ans = W + H;
      if(!bw) ans = std::min(ans, std::min(inter(0, w, x1, x2), inter(W-w, W, x1, x2)));
      if(!bh) ans = std::min(ans, std::min(inter(0, h, y1, y2), inter(H-h, H, y1, y2)));
      std::cout << ans;
      std::cout << ".000000000000" << std::endl;
    }
  }

  return 0;
}