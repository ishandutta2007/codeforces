#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 1e5 + 5;
vector<ll> clist [MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> cnts (m);
  for (int i = 0; i < m; i++) {
    cnts[i] = {0, i};
  }
  
  for (int i = 0; i < n; i++) {
    int subj, skill;
    cin >> subj >> skill;
    subj--;

    cnts[subj].first++;
    clist[subj].push_back(skill);
  }

  for (int i = 0; i < m; i++) {
    sort(clist[i].begin(), clist[i].end(), greater<int> ());

    for (int j = 1; j < (int) clist[i].size(); j++) {
      clist[i][j] += clist[i][j - 1];
    }
  }

  sort(cnts.begin(), cnts.end(), greater<pair<int, int>> ());

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    while (!cnts.empty() && cnts.back().first < i) {
      cnts.pop_back();
    }

    ll cur = 0;
    for (auto pr : cnts) {
      if (clist[pr.second][i - 1] > 0) {
        cur += clist[pr.second][i - 1];
      }
    }
    ans = max(ans, cur);
  }

  cout << ans << '\n';
}