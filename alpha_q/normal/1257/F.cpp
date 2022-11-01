#include <bits/stdc++.h>

using namespace std;

int n, a[105];
map <vector <int>, int> num;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < 1 << 15; ++i) {
    vector <int> vec;
    for (int j = 0; j < n; ++j) vec.emplace_back(__builtin_popcount((a[j] >> 15) ^ i));
    int mn = *min_element(vec.begin(), vec.end());
    for (auto &it : vec) it -= mn; num[vec] = i;
  }
  int all = (1 << 15) - 1;
  for (int i = 0; i < 1 << 15; ++i) {
    vector <int> vec;
    for (int j = 0; j < n; ++j) vec.emplace_back(-__builtin_popcount((a[j] & all) ^ i));
    int mn = *min_element(vec.begin(), vec.end());
    for (auto &it : vec) it -= mn;
    if (num.find(vec) != num.end()) {
      cout << (num[vec] << 15 | i) << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}