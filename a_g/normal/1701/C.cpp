#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      x--;
      a[x]++;
    }
    int low = 0;
    int high = 2*m+1;
    while (high-low > 1) {
      int mid = (low+high)/2;
      long long tasksdone = 0;
      for (int i = 0; i < n; i++) {
        tasksdone += min(a[i], mid) + (mid-min(a[i], mid))/2;
      }
      if (tasksdone >= m) high = mid;
      else low = mid;
    }
    cout << high << '\n';
  }
}