#include <bits/stdc++.h>
using namespace std;

template<typename T, const T& (*op)(const T&, const T&)>
class sparseTable {
  public:
    vector<vector<T>> st;
    sparseTable (vector<T> vals) {
      int n = vals.size();
      int rows = __lg(n)+1;
      st.resize(rows);
      st[0] = vals;
      for (int j = 1; j < rows; j++) {
        st[j].resize(n);
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[j][i] = op(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
      }
    }
    T query(int l, int r) {
      int j = __lg(r-l+1);
      return op(st[j][l], st[j][r-(1<<j)+1]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int d, n, m;
  cin >> d >> n >> m;
  vector<pair<int, int>> stations(m);
  for (pair<int, int>& s: stations) {
    cin >> s.second >> s.first;
  }
  sort(stations.begin(), stations.end(), [&] (pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
      });
  sparseTable<pair<int, int>, min> st(stations);

  int cur = 0;
  long long ans = 0;
  int l = 0;
  int r = 0;
  while (cur+n < d) {
    // find the cheapest gas in [cur+1, cur+n]
    // any stations with index in [l, r) is good
    while (r < m && stations[r].second <= cur+n) r++;
    while (l < m && stations[l].second <= cur) l++;
    if (l == r) {
      cout << "-1\n";
      return 0;
    }
    pair<int, int> station = st.query(l, r-1);
    int distance = min((r == m ? d : stations[r].second)-cur-n, station.second-cur);
    ans += 1LL*station.first*(distance);
    cur += distance;
  }
  cout << ans << '\n';
}