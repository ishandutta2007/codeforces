#include <iostream>
#include <vector>

#define int long long

int find(int n) {
  if(n <= 1)
    return 1;

  int next = find(n/2);
  return 2*next+1;
}

int count(int n) {
  if(n <= 1)
    return (n==1);

  int next = find(n/2);
  return 2*next+(n%2);
}

int ans(int n, int l, int r) {
  if(n <= 1)
    return n%2;

  int s = find(n/2);
  if(r < s)
    return ans(n/2, l, r);
  else if(r == s && l < s)
    return ans(n/2, l, s-1) + (n%2);
  else if(l > s)
    return ans(n/2, l-s-1, r-s-1);
  else if(l == s && r > s)
    return ans(n/2, 0, r-s-1) + (n%2);
  else if(l == s && r == s)
    return (n%2);
  else
    return ans(n/2, l, s-1) + (n%2) + ans(n/2, 0, r-s-1);
}

signed main() {
  int n, l, r;
  std::cin >> n >> l >> r;

  std::cout << ans(n, l-1, r-1) << std::endl;

  return 0;
}