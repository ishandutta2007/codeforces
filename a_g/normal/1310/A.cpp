#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i].second;
  }
  sort(p.begin(), p.end());
  int index = 0;
  multiset<int, greater<int>> times;
  ll ans = 0;
  int count = 0;
  ll timesum = 0;
  while (times.size() > 0 || index < n) {
    if (times.size() == 0) {
      count = p[index].first;
      times.insert(p[index].second);
      timesum = p[index].second;
      index++;
    }
    while (index < n && p[index].first == count) {
      times.insert(p[index].second);
      timesum += p[index].second;
      index++;
    }
    ans += timesum-*times.begin();
    timesum -= *times.begin();
    times.erase(times.begin());
    count++;
  }
  cout << ans << endl;
}