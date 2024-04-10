#include <bits/stdc++.h>

long long query(int l, int r) {
  std::cout << "? " << l + 1 << " " << r << std::endl;
  long long res;
  std::cin >> res;
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int l = 0, r = n;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (query(0, mid + 1) == 0) {
        l = mid;
      } else {
        r = mid;
      }
    }
    int i = l;
    int j = i + query(i, n) - query(i + 1, n) + 1;
    int k = j + query(j, n) - query(j + 1, n) + 1;
    std::cout << "! " << i + 1 << " " << j + 1 << " " << k << std::endl;
  }
}