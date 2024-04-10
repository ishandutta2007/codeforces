#include <iostream>
#include <vector>

#define int long long

const int MAXN = 1000005;

int pr[MAXN];
std::vector<int> prs;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 2; i < MAXN; i++) {
    if(pr[i])
      continue;
    prs.push_back(i);
    for(int j = i*i; j < MAXN; j+=i)
      pr[j] = 1;
  }

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int nc = n;
    int p = 2;
    while(nc%2 == 0) {
      p <<= 1;
      nc >>= 1;
    }

    if(p < 1e9 && p*(p+1) <= 2*n)
      std::cout << p << std::endl;
    else {
      int done = -1;
      if(nc > 1 && nc < 1e9 &&  nc*(nc+1) <= 2*n)
        done = nc;
      else {
        for(int j = 3; j*j <= nc; j++) {
          if(j*(j+1) > 2*n)
            break;
          if(nc%j == 0)
            done = j;
        }
      }

      std::cout << done << std::endl;
    }
  }

  return 0;
}