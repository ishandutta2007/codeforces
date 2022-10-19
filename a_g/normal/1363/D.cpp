#include <bits/stdc++.h>
using namespace std;

int query_range(int l, int r) {
  cout << "? " << r-l+1;
  for (int x = l; x <= r; x++) cout << ' ' <<  x+1;
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> id(n);
    for (int i = 1; i <= k; i++) {
      int c;
      cin >> c;
      for (int j = 0; j < c; j++) {
        int v;
        cin >> v;
        id[v-1] = i;
      }
    }
    int mx = query_range(0, n-1);
    int low = -1;
    int high = n-1;
    while (high-low > 1) {
      int mid = (low+high)/2;
      if (query_range(0, mid) == mx) high = mid;
      else low = mid;
    }
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
      if (id[high] != i+1) ans[i] = mx;
    }
    if (id[high]) {
      vector<int> a;
      for (int i = 0; i < n; i++) {
        if (id[i] != id[high]) a.push_back(i);
      }
      cout << "? " << a.size();
      for (int x: a) cout << ' ' << x+1;
      cout << endl;
      int z;
      cin >> z;
      ans[id[high]-1] = z;
    }

    cout << "!";
    for (int x: ans) cout << ' ' << x;
    cout << endl;

    string verdict;
    cin >> verdict;
    assert(verdict == "Correct");
  }
}