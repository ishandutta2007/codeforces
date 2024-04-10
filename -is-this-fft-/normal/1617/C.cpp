#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

bool seen [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    seen[i] = false;
  }

  vector<int> have;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x <= n) {
      if (seen[x]) {
        have.push_back(x);
      } else {
        seen[x] = true;
      }
    } else {
      have.push_back(x);
    }
  }

  vector<int> need;
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) {
      need.push_back(i);
    }
  }

  sort(have.begin(), have.end());
  sort(need.begin(), need.end());

  for (int i = 0; i < (int) have.size(); i++) {
    if (have[i] <= 2 * need[i]) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << (int) have.size() << '\n';
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