#include <bits/stdc++.h>

using namespace std;

int main() {
  int sz[3]; 
  vector <int> vec[3];
  long long sum = 0;
  cin >> sz[0] >> sz[1] >> sz[2];
  vector <int> mins;
  for (int i = 0; i < 3; ++i) {
    vec[i].resize(sz[i]);
    for (int j = 0; j < sz[i]; ++j) {
      scanf("%d", &vec[i][j]);
      sum += vec[i][j];
    }
    sort(vec[i].begin(), vec[i].end());
    mins.emplace_back(vec[i][0]);
  }
  sort(mins.begin(), mins.end());
  long long ans = sum - 2 * (mins[0] + mins[1]);
  for (int i = 0; i < 3; ++i) {
    long long off = 0;
    for (int x : vec[i]) off += x;
    ans = max(ans, sum - 2 * off);
  }
  cout << ans << '\n';
  return 0;
}