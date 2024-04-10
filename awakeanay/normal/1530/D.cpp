#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> a(n, 0), b(n, 0), deg(n, 0), last(n, -1), vis(n, -1);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i]--;
      b[i] = a[i];
      deg[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
      int cur = i;
      while(1) {
        int next = b[cur];
        if(vis[next] != -1) {
          if(vis[next] != i)
            break;
          
          int id = next;
          int cn = next;
          while(1) {
            int nx = b[cn];
            last[nx] = cn;
            if(nx == id) {
              break;
            }
            cn = nx;
          }
          break;
        }
        vis[next] = i;
        cur = next;
      }
    }

    for(int i = 0; i < n; i++) {
      if(deg[i])
        continue;
      int cur = i;
      while(1) {
        int next = b[cur];
        if(last[next] != -1) {
          last[i] = last[next];
          last[next] = cur;
          b[last[i]] = i;
          break;
        }
        last[next] = cur;
        cur = next;
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
      if(a[i] == b[i])
        ans++;

    std::cout << ans << std::endl;
    for(int j : b)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}