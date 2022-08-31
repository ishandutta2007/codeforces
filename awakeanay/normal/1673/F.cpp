#include <iostream>

#define int long long

const int MAXN = 32;
const int MAXM = 1024;

int pos[MAXN][MAXN];
std::pair<int, int> val[MAXM];

int gray(int n) {
  return n^(n >> 1);
}

int merge(int x, int y) {
  int ans = 0;
  int cur = 1;
  while(x > 0 || y > 0) {
    ans += (x&1)*cur;
    cur *= 2;
    ans += (y&1)*cur;
    cur *= 2;
    x /= 2;
    y /= 2;
  }
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      pos[i][j] = merge(gray(i), gray(j));
      val[pos[i][j]] = {i, j};
    }
  }

  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      std::cout << (pos[i][j-1]^pos[i][j]) << " ";
      sum += pos[i][j-1]^pos[i][j];
    }
    std::cout << std::endl;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << (pos[i][j]^pos[i-1][j]) << " ";
      sum += pos[i][j]^pos[i-1][j];
    }
    std::cout << std::endl;
  }

  int cur = pos[0][0];
  while(k--) {
    int x;
    std::cin >> x;
    cur ^= x;
    std::cout << val[cur].first+1 << " " << val[cur].second+1 << std::endl;
  }

  return 0;
}