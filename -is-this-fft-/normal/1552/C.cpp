#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  set<int> frees;
  for (int i = 0; i < 2 * n; i++) {
    frees.insert(i);
  }
  
  vector<pair<int, int>> chords;
  for (int i = 0; i < K; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    if (u > v) {
      swap(u, v);
    }

    frees.erase(u);
    frees.erase(v);

    chords.push_back(make_pair(u, v));
  }

  vector<int> oths (frees.begin(), frees.end());
  int step = (int) oths.size() / 2;
  for (int i = 0; i < step; i++) {
    chords.push_back(make_pair(oths[i], oths[i + step]));
  }

  int ans = 0;
  for (auto a : chords) {
    for (auto b : chords) {
      if (a.first < b.first && b.first < a.second && a.second < b.second) {
        ans++;
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