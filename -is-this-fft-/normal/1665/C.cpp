#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
  }

  vector<int> szs;
  for (int i = 1; i <= n; i++) {
    if (!adj[i].empty()) {
      szs.push_back(adj[i].size());
    }
  }
  szs.push_back(1);

  sort(szs.begin(), szs.end(), greater<int>());
  int ans = 0;
  set<pair<int, int>> ends;
  for (int i = 0; true; i++) {
    if (i < (int) szs.size()) {
      ends.insert({szs[i] + i, i});
    } else {
      if (ends.rbegin()->first <= i + 1) {
        ans = ends.rbegin()->first;
        break;
      }

      // try to reduce by extra injection
      auto pr = *ends.rbegin();
      ends.erase(pr);
      pr.first--;
      ends.insert(pr);

      if (ends.rbegin()->first <= i + 1) {
        ans = i + 1;
        break;
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}