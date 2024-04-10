#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<vector<int>> indices(26);
    for (int i = n-1; i >= 0; i--) {
      indices[s[i]-'a'].push_back(i);
    }
    fenwick<int> fenw(n);

    long long tot = 0;
    long long ans = INF;
    for (int i = 0; i < n; i++) {
      int c = t[i]-'a';
      for (int j = 0; j < c; j++) {
        if (indices[j].size()) {
          int k = indices[j].back()+1;
          ans = min(ans, tot+k-fenw.query(k)-1);
        }
      }

      if (!indices[c].size()) break;
      int k = indices[c].back()+1;
      tot += k-fenw.query(k)-1;
      fenw.add(k, 1);
      indices[c].pop_back();
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }
}