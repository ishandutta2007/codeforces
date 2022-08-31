#include <iostream>
#include <vector>

#define int long long

int near(int a, int b) {
  return (b == a+1 || a == b+1);
}

const int MAXN = 2025;

std::vector<int> ans;
int seq[MAXN];

void add(int x) {
  ans.push_back(x+1);
  for(int i = 0; 2*i < x; i++) {
    int temp = seq[i];
    seq[i] = seq[x-i];
    seq[x-i] = temp;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    ans.clear();

    int n;
    std::cin >> n;

    bool poss = true;
    for(int i = 0; i < n; i++) {
      std::cin >> seq[i];
      seq[i]--;
      if(seq[i]%2 != i%2)
        poss = false;
    }

    if(!poss) {
      std::cout << -1 << std::endl;
      continue;
    }

    for(int i = n-1; i > 0; i-=2) {
      for(int j = 2; j <= i; j+=2) {
        if(seq[j] == i) {
          add(j);
          break;
        }
      }

      for(int j = 1; j <= i-1; j+=2) {
        if(seq[j] == i-1) {
          add(j-1);
          add(j+1);
          add(2);
          add(i);
          break;
        }
      }
    }

    if(!poss) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::cout << ans.size() << std::endl;
    for(int j : ans)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}