#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> indices(n+1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    indices[x].push_back(i);
  }
  int l = 0, r = n;
  // "either side" occurs strictly between l and r
  fenwick<int> f(n+1);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    if (indices[i].empty()) continue;
    int ol = l;
    l = min(r-1, indices[i].front()-1);
    r = max(ol+1, indices[i].back()+1);
    for (int j: indices[i]) f.add(j, 1);
    ans += f.query(r-1)-f.query(l);
  }
  cout << ans << '\n';
}