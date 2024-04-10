#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, T;
  cin >> n >> T;
  vector<pair<int, int>> a(n);
  for (pair<int, int>& p: a) {
    cin >> p.first >> p.second;
  }

  vector<int> valid_problems;
  auto check = [&] (int x) {
    valid_problems.clear();
    for (int i = 0; i < n; i++) {
      if (a[i].first >= x) valid_problems.push_back(i);
    }
    sort(valid_problems.begin(), valid_problems.end(),
        [&] (int x, int y) {return a[x].second < a[y].second;});
    if ((int)valid_problems.size() < x) return false;
    long long time_spent = 0;
    for (int i = 0; i < x; i++) {
      time_spent += a[valid_problems[i]].second;
    }
    return time_spent <= T;
  };

  int low = 0;
  int high = n+1;
  while (high-low > 1) {
    int mid = (low+high)/2;
    if (check(mid)) low = mid;
    else high = mid;
  }
  check(low);
  cout << low << '\n' << low << '\n';
  for (int i = 0; i < low; i++) {
    cout << valid_problems[i]+1 << ' ';
  }
  cout << '\n';
}