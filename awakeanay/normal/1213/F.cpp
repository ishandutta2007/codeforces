#include <iostream>

#define int long long

const int MAXN = 200005;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  int p[n], q[n];
  for(int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
  }

  int rq[n];
  for(int i = 0; i < n; i++) {
    std::cin >> q[i];
    q[i]--;
    rq[q[i]] = i;
  }

  int pq[n];
  for(int i = 0; i < n; i++) {
    pq[i] = rq[p[i]];
  }

  std::string s(n, 'a');
  int chars = 0;
  int it = 0;
  bool poss = true;

  int last = -1;
  while(it < n) {
    int max = pq[it];
    while(it < max) {
      it++;
      max = std::max(max, pq[it]);
    }
    if(chars < k) {
      chars++;
    }

    for(int i = it; i > last; i--)
      s[p[i]] = ('a' + chars - 1);

    last = it;
    it++;
  }

  if(chars >= k) {
    std::cout << "YES" << std::endl;
    std::cout << s << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}