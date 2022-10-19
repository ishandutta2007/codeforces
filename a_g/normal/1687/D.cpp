#include <bits/stdc++.h>
using namespace std;

long long dist(pair<long long, int> p) {
  int n = floor(sqrt(p.first));
  if (p.first+p.second-1 <= 1LL*n*n+n) return 0;
  n = max(n+1, p.second-1);
  return 1LL*n*n-p.first;
}

long long solve(vector<pair<long long, int>>& a) {
  vector<pair<long long, int>> compressed;
  for (pair<long long, int>& p: a) {
    if (!compressed.size()) {
      compressed.push_back(p);
      continue;
    }
    long long gap = p.first - (compressed.back().first+compressed.back().second);
    int n = floor(sqrt(compressed.back().first));
    if (n > gap) {
      compressed.back().second = p.first+p.second-compressed.back().first;
    }
    else {
      compressed.push_back(p);
    }
  }
  long long k = 0;
  for (pair<long long, int>& p: compressed) {
    k = max(k, dist(p));
  }
  if (k == 0) return 0;
  for (pair<long long, int>& p: compressed) {
    p.first += k;
  }
  return k+solve(compressed);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, int>> a(n);
  for (pair<long long, int>& p: a) {
    cin >> p.first;
    p.second = 1;
  }
  cout << solve(a) << '\n';
}