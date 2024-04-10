#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 200005;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> help;
  std::pair<int, int> arr[n];

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    help.push_back(x);
    arr[i].second = x;
  }

  for(int i = 0; i < n; i++) {
    std::cin >> arr[i].first;
  }

  std::sort(help.begin(), help.end());
  for(int i = 0; i < n; i++) {
  }
  std::sort(arr, arr+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int cur = std::lower_bound(help.begin(), help.end(), arr[i].second)-help.begin();
    ans += sum(cur)*arr[i].second;
    add(cur, 1);
  }

  for(int i = 0; i <= n; i++) {
    bit[i] = 0;
  }

  for(int i = n-1; i >= 0; i--) {
    int cur = std::lower_bound(help.begin(), help.end(), arr[i].second)-help.begin();
    cur = n-1-cur;
    ans -= sum(cur)*arr[i].second;
    add(cur, 1);
  }

  std::cout << ans << std::endl;

  return 0;
}