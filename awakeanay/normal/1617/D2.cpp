#include <iostream>
#include <vector>

#define int long long

int query(int x, int y, int z) {
  std::cout << "? " << x+1 << " " << y+1 << " " << z+1 << std::endl;
  int ret;
  std::cin >> ret;
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int v[n/3];
    int f;

    for(int i = 0; i < n; i+=3) {
      v[i/3] = query(i, i+1, i+2);
      if(i) {
        if(v[i/3] != v[i/3-1]) {
          f = i/3;
        }
      }
    }

    int take[2];
    int last = v[f-1];
    int x = (f-1)*3;
    int y = x+6;
    for(int i = x+1; i+3 <= y; i++) {
      int cur = (i+3 == y ? (!last) : query(i, i+1, i+2));
      if(cur != last) {
        take[last] = i-1;
        take[cur] = i+2;
        a[i-1] = last;
        a[i+2] = cur;

        for(int j = x; j < x+6; j++) {
          if(j == take[last] || j == take[cur])
            continue;

          a[j] = query(j, take[last], take[cur]);
        }

        break;
      }
    }

    for(int i = 0; i < n/3; i++) {
      if(i == f || i == f-1)
        continue;
      int u = 3*i;
      int p = query(u, u+1, take[!v[i]]);
      int q = query(u+1, u+2, take[!v[i]]);

      if(p == v[i] && q == v[i]) {
        a[u] = a[u+1] = a[u+2] = v[i];
      }
      else if(p == v[i]) {
        a[u] = a[u+1] = v[i];
        a[u+2] = !v[i];
      }
      else if(q == v[i]) {
        a[u+1] = a[u+2] = v[i];
        a[u] = !v[i];
      }
      else {
        a[u] = a[u+2] = v[i];
        a[u+1] = !v[i];
      }
    }

    std::vector<int> ans;
    for(int i = 0; i < n; i++)
      if(!a[i])
        ans.push_back(i);

    std::cout << "! " << ans.size() << " ";
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}