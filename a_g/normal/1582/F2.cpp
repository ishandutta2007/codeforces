#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  const int K = 5001;
  const int M = 8192;
  vector<vector<int>> cumulative(K, vector<int>({0}));
  vector<int> min_indices(M, K);
  min_indices[0] = 0;
  while (n--) {
    int val;
    cin >> val;
    if (val > 0) {
      for (int j: cumulative[val-1]) {
        int x = j^val;
        for (int k = val; k < min_indices[x]; k++) {
          cumulative[k].push_back(x);
        }
        min_indices[x] = min(min_indices[x], val);
      }
      cumulative[val-1].clear();
    }
  }
  vector<int> values = cumulative[K-1];
  sort(values.begin(), values.end());
  cout << values.size() << endl;
  for (int x: values) {
    cout << x << " ";
  }
  cout << endl;
}