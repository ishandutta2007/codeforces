#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  vector<double> all;
  all.reserve(2 * n + 1);
  all.push_back(1e9 + 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    all.push_back(a[i].first);
    all.push_back(a[i].second);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for(int i = all.size(); i > 0; i--) {
    all.push_back((all[i - 1] + all[i]) * 0.5);
  }
  sort(all.begin(), all.end());
  int m = all.size();
  vector<int> add(m, 0);
  for(int i = 0; i < n; i++) {
    a[i].first = lower_bound(all.begin(), all.end(), a[i].first) - all.begin();
    a[i].second = lower_bound(all.begin(), all.end(), a[i].second + 0.1) - all.begin();
    add[a[i].first]++;
    add[a[i].second]--;
  }
  for(int i = 1; i < m; i++) {
    add[i] += add[i - 1];
  }
  vector<pair<int, int>> segs;
  for(int i = 0; i < m; i++) {
    if(add[i] >= k) {
      int j = i;
      while(j < m - 1 && add[j + 1] >= k) {
        j++;
      }
      segs.push_back(make_pair(all[i], all[j]));
      i = j;
    }
  }
  cout << segs.size() << '\n';
  for(auto p : segs) {
    cout << p.first << ' ' << p.second << '\n';
  }
}