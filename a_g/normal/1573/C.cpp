#include <bits/stdc++.h>
#define ll long long
using namespace std;

int update(int i, map<int, int>& readcycle, vector<vector<int>>& dependencies, set<int>& waitingchapters) {
  //cout << i << endl;
  if (readcycle[i] != -1) {
    //cout << "already done" << endl;
    return readcycle[i];
  }
  if (waitingchapters.find(i) != waitingchapters.end()) {
    //cout << "loop" << endl;
    return -1;
  }
  if (dependencies[i].size() == 0) {
    readcycle[i] = 1;
    return 1;
  }
  int ans = 0;
  for (int l: dependencies[i]) {
    waitingchapters.insert(i);
    int j = update(l, readcycle, dependencies, waitingchapters);
    if (j == -1) return -1;
    if (l < i) {
      ans = max(ans, j);
    }
    else {
      ans = max(ans, j+1);
    }
    waitingchapters.erase(i);
  }
  readcycle[i] = ans;
  //cout << ans << endl;
  return readcycle[i];
}

int main () {
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<int>> dependencies(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> k;
      for (int j = 0; j < k; j++) {
        int l;
        cin >> l;
        dependencies[i].push_back(l);
      }
    }
    map<int, int> readcycle;
    for (int i = 1; i <= n; i++) {
      readcycle[i] = -1;
    }
    set<int> waitingchapters;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int j = update(i, readcycle, dependencies, waitingchapters);
      //cout << i << " " << j << endl;
      if (j == -1) {
        ans = -1;
        break;
      }
      else {
        ans = max(ans, j);
      }
    }
    cout << ans << endl;
  }
}