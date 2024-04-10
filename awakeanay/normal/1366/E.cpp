#include <iostream>
#include <algorithm>
#include <map>

#define int long long
#define MOD 998244353

signed main() {
  int n, m;
  std::cin >> n >> m;

  int arr[n+1];
  std::map<int, int> last;
  std::map<int, int> mark;
  for(int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    last[arr[i]] = i;
  }

  bool poss = true;
  int ans = 1;
  int last_id = 0;

  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    mark[x] = 1;
    if(!last[x])
      poss = false;
  }

  std::sort(arr+1, arr+n+1);

  int first = 1;
  for(int i = 1; i <= n; i++) {
    if(i > 1 && arr[i] == arr[i-1])
      continue;

    int cur = last[arr[i]];
    //std::cout << arr[i] << " " << cur << " " << mark[i] << " screen " << std::endl;

    if(mark[arr[i]] == 1) {
      //std::cout << arr[i] << " " << cur << " " << last_id << std::endl;
      if(last_id > cur)
        poss = false;

      if(first) {
        first = 0;
        if(i > 1)
          poss = false;
      }
      else {
        ans = (ans*(cur - last_id))%MOD;
      }
    }

    last_id = std::max(cur, last_id);
  }

  if(poss)
    std::cout << ans << std::endl;
  else
    std::cout << 0 << std::endl;

  return 0;
}