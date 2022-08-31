#include <iostream>
#include <algorithm>

#define int long long

int findOr(int x, int y) {
  std::cout << "or " << x << " " << y << std::endl;
  std::cin >> x;
  return x;
}

int findAnd(int x, int y) {
  std::cout << "and " << x << " " << y << std::endl;
  std::cin >> x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  int ab = findAnd(1, 2), bc = findAnd(2, 3), ca = findAnd(3, 1);
  int AB = findOr(1, 2), BC = findOr(2, 3), CA = findOr(3, 1);

  int andAll = ab&bc;
  int orAll = AB|BC;

  int a[n+1];
  a[1] = (ab|ca|(orAll^BC));
  a[2] = (ab|bc|(orAll^CA));
  a[3] = (ca|bc|(orAll^AB));

  for(int i = 4; i <= n; i++) {
    int ori = findOr(i, 1);
    int andi = findAnd(i, 1);

    a[i] = (andi|(ori^a[1]));
  }

  std::sort(a+1, a+n+1);
  std::cout << "finish " << a[k] << std::endl;

  return 0;
}