#include <iostream>

#define int long long

const int INF = 10000000000;

int n;

void app1(int seq[]) {
  for(int i = 0; i < 2*n; i+=2) {
    seq[i] ^= seq[i+1] ^= seq[i] ^= seq[i+1];
  }
}

void app2(int seq[]) {
  for(int i = 0; i < n; i++)
    seq[i] ^= seq[i+n] ^= seq[i] ^= seq[i+n];
}

signed main() {
  std::cin >> n;

  int pg[2*n], init[2*n];
  for(int i = 0; i < 2*n; i++) {
    std::cin >> pg[i];
    pg[i]--;
    init[i] = pg[i];
  }

  int ans = INF;

  int count = -1;
  while(true) {
    if(count >= 0)
      if(count%2)
        app2(pg);
      else
        app1(pg);

    count++;
    bool isS = true;
    for(int i = 0; i < 2*n; i++)
      if(pg[i] != i)
        isS = false;

    if(isS) {
      ans = std::min(ans, count);
      break;
    }

    bool isL = count > 0;
    for(int i = 0; i < 2*n; i++)
      if(pg[i] != init[i])
        isL = false;

    if(isL) {
      break;
    }
  }

  app2(init);
  
  for(int i = 0; i < 2*n; i++)
    pg[i] = init[i];

  count = -1;
  while(true) {
    if(count >= 0)
      if(count%2)
        app2(pg);
      else
        app1(pg);

    count++;
    bool isS = true;
    for(int i = 0; i < 2*n; i++)
      if(pg[i] != i)
        isS = false;

    if(isS) {
      ans = std::min(ans, count+1);
      break;
    }

    bool isL = count > 0;
    for(int i = 0; i < 2*n; i++)
      if(pg[i] != init[i])
        isL = false;

    if(isL) {
      break;
    }
  }

  if(ans == INF)
    std::cout << -1 << std::endl;
  else
    std::cout << ans << std::endl;

  return 0;
}