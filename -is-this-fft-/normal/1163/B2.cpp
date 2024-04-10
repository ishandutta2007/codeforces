#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

int cnt [MAX_N];
set<pair<int, int>> cols;

void add (int u) {
  if (cnt[u] != 0) {
    cols.erase({cnt[u], u});
  }
  cnt[u]++;
  cols.insert({cnt[u], u});
}

bool is_good () {
  if (cols.size() == 1) {
    return true;
  }

  if (cols.begin()->first == cols.rbegin()->first) {
    if (cols.begin()->first == 1) return true;
    else return false;
  }

  if ((cols.begin()->first == 1)
      && (next(cols.begin())->first == cols.rbegin()->first)) {
    return true;
  }

  if ((cols.rbegin()->first == cols.begin()->first + 1) &&
      (next(cols.rbegin())->first == cols.begin()->first)) {
    return true;
  }

  return false;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    add(x);
    if (is_good()) {
      ans = i;
    }
  }

  cout << ans << endl;
}