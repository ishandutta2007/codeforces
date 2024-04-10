#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void solve () {
  int n;
  cin >> n;

  map<int, int> cnt;
  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  map<int, int> open;
  int best = n, last = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > last) {
      break;
    }

    if (!open.count(arr[i])) {
      open[arr[i]] = cnt[arr[i]];
    }

    open[arr[i]]--;
    if (open[arr[i]] == 0) {
      open.erase(arr[i]);
    }

    if (open.empty()) {
      best = i;
    }
    
    last = arr[i];
  }

  set<int> uniq;
  for (int i = 0; i < best; i++) {
    uniq.insert(arr[i]);
  }

  cout << (int) uniq.size() << '\n';
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