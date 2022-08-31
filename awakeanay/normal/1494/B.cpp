#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, u, r, d, l;
    std::cin >> n >> u >> r >> d >> l;

    bool poss = false;
    for(int a = 0; a < 2; a++) {
      for(int b = 0; b < 2; b++) {
        for(int c = 0; c < 2; c++) {
          for(int f = 0; f < 2; f++) {
            int nu, nr, nd, nl;
            nu = u; nr = r; nd = d; nl = l;
            bool cur_poss = true;
            nu -= a + b;
            nr -= b + c;
            nd -= c + f;
            nl -= f + a;

            cur_poss &= 0 <= nu && nu <= n-2;
            cur_poss &= 0 <= nr && nr <= n-2;
            cur_poss &= 0 <= nd && nd <= n-2;
            cur_poss &= 0 <= nl && nl <= n-2;

            poss |= cur_poss;
          }
        }
      }
    }

    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}