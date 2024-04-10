#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

int arr [MAX_N];

bool erase (map<int, int> &mp, int val) {
  if (mp[val] == 0) {
    return false; // all is doomed
  }

  mp[val]--;
  if (mp[val] == 0) {
    mp.erase(val);
  }
  
  return true;
}

bool can (int X, map<int, int> cnt, vector<pair<int, int>> &choices) {
  choices.clear();
  while (!cnt.empty()) {
    int u = cnt.rbegin()->first;
    int v = X - u;
    
    if (!erase(cnt, u)) {
      return false;
    }

    if (!erase(cnt, v)) {
      return false;
    }

    choices.push_back(make_pair(u, v));
    X = u;
  }
  return true;
}

void solve () {
  int n;
  cin >> n;

  map<int, int> cnt;
  
  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  int mx = cnt.rbegin()->first;
  vector<pair<int, int>> choices;
  for (int i = 0; i < n; i++) {
    if (can(mx + arr[i], cnt, choices)) {
      cout << "YES" << '\n';
      cout << choices[0].first + choices[0].second << '\n';
      for (auto pr : choices) {
        cout << pr.first << " " << pr.second << '\n';
      }
      return;
    }
  }
  cout << "NO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}