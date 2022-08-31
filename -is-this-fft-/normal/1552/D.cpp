#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10;

int arr [MAX_N];

bool check (const vector<int> &coef) {
  bool allz = true;
  int sum = 0;
  for (int i = 0; i < (int) coef.size(); i++) {
    sum += arr[i] * coef[i];
    if (coef[i] != 0) {
      allz = false;
    }
  }

  return sum == 0 && !allz;
}

void dfs (vector<int> &cur, int n, bool &found) {
  if ((int) cur.size() == n) {
    if (check(cur)) {
      found = true;
    }
  } else {
    for (int i = -1; i <= 1; i++) {
      cur.push_back(i);
      dfs(cur, n, found);
      cur.pop_back();
    }
  }
}

void solve () {
  int n;
  cin >> n;

  bool anyz = false;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      anyz = true;
    }
  }

  if (anyz) {
    cout << "YES" << '\n';
    return;
  }

  vector<int> coefs;
  bool ans = false;
  dfs(coefs, n, ans);
  if (ans) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
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