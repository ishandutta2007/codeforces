#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

std::vector<int> ans;

const int MAXN = 100005;
const int INF = 1e18+5;

int amt[MAXN];

void print(int n, int k) {
  if(n == 1) {
    ans.push_back(1);
    return;
  }

  for(int q = 1; q <= n; q++) {
    if(amt[n-q] >= k) {
      ans.push_back(q);
      print(n-q, k);
      return;
    }
    else
      k -= amt[n-q];
  }
}

signed main() {
  amt[0] = 1;
  amt[1] = 1;
  for(int i = 2; i < MAXN; i++) {
    amt[i] = amt[i-1]*2;
    if(amt[i] > INF)
      amt[i] = INF;
  }

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    ans.clear();

    if(amt[n] < k) {
      std::cout << -1 << std::endl;
      continue;
    }


    print(n, k);

    int out[n];
    for(int i = 0; i < n; i++)
      out[i] = i+1;

    int cur = 0;
    for(int j : ans) {
      std::reverse(out+cur, out+cur+j);
      cur += j;
    }

    for(int j : out)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}