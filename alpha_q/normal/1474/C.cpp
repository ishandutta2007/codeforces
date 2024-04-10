#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

bool vis[N];
int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n + n; ++i) {
      scanf("%d", a + i);
    }
    sort(a + 1, a + n + n + 1);
    int yo = -1;
    vector <pair <int, int>> ans;
    for (int i = 1; i < n + n; ++i) {
      multiset <int> s(a + 1, a + n + n + 1);
      s.erase(s.find(a[i]));
      s.erase(s.find(a[n + n]));
      int sum = a[n + n];
      vector <pair <int, int>> cur;
      cur.emplace_back(a[i], a[n + n]);
      bool good = 1;
      while (!s.empty()) {
        int x = *s.rbegin();
        s.erase(s.find(x));
        auto it = s.find(sum - x);
        if (it == s.end()) {
          good = 0;
          break;
        }
        s.erase(it); 
        cur.emplace_back(sum - x, x);
        sum = x;
      }
      if (good) {
        yo = a[i] + a[n + n], ans = cur; 
        break;
      }
    }
    if (ans.empty()) {
      puts("NO");
    } else {
      puts("YES");
      printf("%d\n", yo);
      for (auto [x, y] : ans) printf("%d %d\n", x, y);
    }
  }
  return 0;
}