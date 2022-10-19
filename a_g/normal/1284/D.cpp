#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& sa, vector<int>& ea, vector<int>& sb, vector<int>& eb) {
  int n = (int)sa.size();
  vector<pair<pair<int, bool>, pair<int, int>>> events;
  for (int i = 0; i < n; i++) {
    events.emplace_back(make_pair(sa[i], 1), make_pair(sb[i], eb[i]));
    events.emplace_back(make_pair(ea[i]+1, 0), make_pair(sb[i], eb[i]));
  }
  sort(events.begin(), events.end());
  multiset<int> starts, ends;
  for (auto& ev: events) {
    if (ev.first.second) {
      if (starts.size() && ev.second.second < *starts.rbegin()) return 0;
      if (ends.size() && ev.second.first > *ends.begin()) return 0;
      starts.insert(ev.second.first);
      ends.insert(ev.second.second);
    }
    else {
      starts.erase(starts.find(ev.second.first));
      ends.erase(ends.find(ev.second.second));
    }
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> sa(n), ea(n), sb(n), eb(n);
  for (int i = 0; i < n; i++) {
    cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
  }
  
  cout << (check(sa, ea, sb, eb) && check(sb, eb, sa, ea) ? "YES" : "NO") << '\n';
}