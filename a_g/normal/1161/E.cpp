#include <bits/stdc++.h>
using namespace std;

vector<bool> query(vector<pair<int, int>>& a) {
  int n = (int)a.size();
  vector<bool> ans(n);
  if (a.empty()) return ans;
  cout << "Q " << n;
  for (auto& [u, v]: a) {
    cout << ' ' << u << ' ' << v;
  }
  cout << endl;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    ans[i] = s[i]=='1';
  }
  return ans;
}

vector<bool> query_line(vector<int>& a) {
  int n = (int)a.size();
  vector<pair<int, int>> oddpairs;
  vector<pair<int, int>> evenpairs;
  for (int i = 0; i+1 < n; i++) {
    if (i&1) oddpairs.emplace_back(a[i], a[i+1]);
    else evenpairs.emplace_back(a[i], a[i+1]);
  }
  vector<bool> evenans = query(evenpairs);
  vector<bool> oddans = query(oddpairs);
  vector<bool> ans(n-1);
  for (int i = 0; i+1 < n; i++) {
    if (i&1) ans[i] = oddans[i/2];
    else ans[i] = evenans[i/2];
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<bool> adj_same = query_line(a);
    vector<int> leaders;
    for (int i = 0; i < n; i++) {
      if (i == 0 || !adj_same[i-1]) leaders.push_back(a[i]);
    }

    int m = (int)leaders.size();
    vector<bool> alt_same(m-1);
    for (int z: {0, 1}) {
      vector<int > group;
      for (int i = z; i < m; i += 2) {
        group.push_back(leaders[i]);
      }
      vector<bool> response = query_line(group);
      for (int i = z; i+2 < m; i += 2) {
        alt_same[i] = response[i/2];
      }
    }
    vector<int> leaders_tag(m);
    if (m) leaders_tag[1] = 1;
    for (int i = 2; i < m; i++) {
      if (alt_same[i-2]) leaders_tag[i] = leaders_tag[i-2];
      else leaders_tag[i] = 3-leaders_tag[i-1]-leaders_tag[i-2];
    }
    vector<int> tag(n);
    for (int i = 0; i < m; i++) {
      tag[leaders[i]-1] = leaders_tag[i];
    }
    for (int i = 1; i < n; i++) {
      if (adj_same[i-1]) {
        tag[i] = tag[i-1];
      }
    }

    cout << "A";
    for (int z = 0; z < 3; z++) {
      cout << ' ' << count(tag.begin(), tag.end(), z);
    }
    cout << '\n';
    for (int z = 0; z < 3; z++) {
      for (int i = 0; i < n; i++) {
        if (tag[i] == z) {
          cout << i+1 << ' ';
        }
      }
      cout << '\n';
    }
    cout << endl;
  }
}