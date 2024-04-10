#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<vector<ll>> a(n);
  vector<int> maxbuild(n);
  for (int i = 0; i < n; i++) {
    cin >> maxbuild[i];
    vector<ll> items(maxbuild[i]);
    for (int j = 0; j < maxbuild[i]; j++) {
      cin >> items[j];
    }
    a[i] = items;
  }
  int m;
  cin >> m;
  set<vector<int>> banned;
  for (int i = 0; i < m; i++) {
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
      cin >> b[j];
    }
    banned.insert(b);
  }
  queue<pair<vector<int>, int>> builds;
  builds.push({maxbuild, 0});
  ll maxstrength = 0;
  vector<int> bestbuild;
  while (!builds.empty()) {
    pair<vector<int>, int> buildpair = builds.front();
    builds.pop();
    if (banned.find(buildpair.first) != banned.end()) {
      for (int i = buildpair.second; i < n; i++) {
        vector<int> newbuild = buildpair.first;
        newbuild[i]--;
        if (newbuild[i]) {
          builds.push({newbuild, i});
        }
      }
    }
    else {
      ll strength = 0;
      for (int i = 0; i < n; i++) {
        strength += a[i][buildpair.first[i]-1];
      }
      if (strength > maxstrength) {
        maxstrength = strength;
        bestbuild = buildpair.first;
      }
    }
  }
  for (int i: bestbuild) {
    cout << i << " ";
  }
  cout << '\n';
}