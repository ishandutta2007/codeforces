#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 55;

int x [MAX_N], y [MAX_N];

bool paral (int a, int b, int c, int d) {
  if (x[a] - x[b] == 0 && x[c] - x[d] == 0) return true;
  if (x[a] - x[b] == 0 || x[c] - x[d] == 0) return false;
  return (x[a] - x[b]) * (y[c] - y[d]) == (x[c] - x[d]) * (y[a] - y[b]);
}

bool same (int a, int b, int c, int d) {
  if (!paral(a, b, c, d)) return false;
  if (x[a] - x[b] == 0 && x[c] - x[d] == 0) return (x[a] == x[c]);
  if (y[a] - y[b] == 0 && y[c] - y[d] == 0) return (y[a] == y[c]);
  return (x[a] - x[b]) * (y[a] - y[c]) == (x[a] - x[c]) * (y[a] - y[b]);
}

int del [MAX_N][MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<pair<int, int>> lines;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      lines.push_back({i, j});
    }
  }

  for (int i = 0; i < (int) lines.size(); i++) {
    for (int j = i + 1; j < (int) lines.size(); j++) {
      if (same(lines[i].first, lines[i].second, lines[j].first, lines[j].second)) {
        del[lines[j].first][lines[j].second] = 1;
      }
    }
  }

  vector<pair<int, int>> rlines;
  for (int i = 0; i < (int) lines.size(); i++) {
    if (!del[lines[i].first][lines[i].second]){
      rlines.push_back(lines[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i < (int) rlines.size(); i++) {
    for (int j = i + 1; j < (int) rlines.size(); j++) {
      if (!paral(rlines[i].first, rlines[i].second, rlines[j].first, rlines[j].second)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}