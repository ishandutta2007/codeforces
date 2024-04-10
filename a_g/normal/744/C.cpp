#include <bits/stdc++.h>
using namespace std;

const int N = 16;
vector<pair<int, int>> dp[1<<N];
int red[1<<N], blue[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<bool, pair<int, int>>> cards(n);
  for (int i = 0; i < n; i++) {
    char c;
    int r, b;
    cin >> c >> r >> b;
    cards[i] = make_pair(c=='R', make_pair(r, b));
  }

  dp[0].emplace_back(0, 0);
  for (int mask = 0; mask < (1<<n); mask++) {
    //cout << mask << '\n';
    sort(dp[mask].begin(), dp[mask].end());
    vector<pair<int, int>> processed;
    for (pair<int, int>& p: dp[mask]) {
      if (processed.empty() || p.second < processed.back().second) processed.emplace_back(p);
    }
    swap(processed, dp[mask]);
    /*
    for (pair<int, int>& p: dp[mask]) {
      cout << p.first << ' ' << p.second << '\n';
    }
    */
    for (int i = 0; i < n; i++) {
      if (!((mask>>i)&1)) {
        int newmask = mask|(1<<i);
        red[newmask] = red[mask] + cards[i].first;
        blue[newmask] = blue[mask] + 1-cards[i].first;
        for (pair<int, int>& p: dp[mask]) {
          dp[newmask].emplace_back(
              p.first+max(cards[i].second.first-red[mask], 0),
              p.second+max(cards[i].second.second-blue[mask], 0));
        }
      }
    }
  }

  int ans = 1e9;
  for (pair<int, int>& p: dp[(1<<n)-1]) {
    ans = min(ans, max(p.first, p.second));
  }
  cout << ans+n << '\n';
}