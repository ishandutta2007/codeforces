#include <iostream>
#include <vector>

#define int long long

std::vector<int> bit;

void add(int x) {
  x += 1;
  while(x < bit.size()) {
    bit[x]++;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int inv = 0;
  int best_c = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(a[j] < a[i])
        inv++;
    }
  }

  int best = inv;

  for(int i = 0; i < n; i++) {
    bit = std::vector<int> (n+5, 0);
    for(int j = i+1; j < n; j++) {
      if(a[i] > a[j]) {
        int cur = 0;
        cur = sum(a[i]);
        cur -= sum(a[j]);
        cur = 2*cur + 1;
        if(inv - cur < best) {
          best = inv-cur;
          best_c = 1;
        }
        else if(best == inv-cur)
          best_c++;
      }
      add(a[j]);
    }
  }

  std::cout << best << " " << best_c << std::endl;

  return 0;
}