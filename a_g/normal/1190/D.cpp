#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 4e5+2;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pii> pts(n);
  set<int> coords;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first;
    cin >> pts[i].second;
    coords.insert(pts[i].first);
    coords.insert(pts[i].second);
  }
  map<int, int> compress;
  int index = 0;
  for (int i: coords) {
    compress[i] = index;
    index++;
  }
  vector<vector<int>> rows(maxn);
  for (int i = 0; i < n; i++) {
    pts[i].first = compress[pts[i].first];
    pts[i].second = compress[pts[i].second];
    rows[pts[i].second].push_back(pts[i].first);
  }
  ordered_set<int> xcoords;
  ll ans = 0;
  for (int i = maxn-1; i >= 0; i--) {
    int k = rows[i].size();
    if (k) {
      sort(rows[i].begin(), rows[i].end());
      ll contrib = 0;
      vector<int> groups(k+1);
      groups[0] = xcoords.order_of_key(rows[i][0]);
      groups[k] = xcoords.size() - xcoords.order_of_key(rows[i][k-1]+1);
      for (int j = 1; j < k; j++) {
        groups[j] = xcoords.order_of_key(rows[i][j]) - xcoords.order_of_key(rows[i][j-1]+1);
      }
      ll sum = 0;
      for (ll val: groups) {
        contrib -= (val+1)*(val+1);
        sum += val+1;
      }
      contrib += sum*sum;
      ans += contrib/2;
      for (int j: rows[i]) xcoords.insert(j);
    }
  }
  cout << ans << endl;
}