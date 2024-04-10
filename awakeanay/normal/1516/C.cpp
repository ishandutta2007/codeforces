#include <iostream>
#include <vector>

#define int long long

const int MAXA = 200005;

int p2(int x) {
  int c = 0;
  for(int i = 0; i < 20; i++) {
    if(x%(1 << i))
      break;
    c++;
  }
  return c;
}

signed main() {
  int n;
  std::cin >> n;

  int min = 0;
  int a[n];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  for(int i = 1; i < n; i++)
    if(p2(a[i]) < p2(a[min]))
      min = i;

  std::vector<int> poss(MAXA, 0);
  poss[0] = 1;

  for(int i = 0; i < n; i++) {
    for(int j = MAXA-1; j-a[i] >= 0; j--)
      poss[j] |= poss[j-a[i]];
  }

  int cposs = 0;
  if(sum%2 == 0 && poss[sum/2])
    cposs = 1;

  if(cposs) {
    std::cout << 1 << std::endl << min+1 << std::endl;
  }
  else {
    std::cout << 0 << std::endl;
  }

  return 0;
}