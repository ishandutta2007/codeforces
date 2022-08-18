#include <iostream>
#include <vector>

using namespace std;

const int ALPHA = 26;

vector<int> read_str (int n) {
  vector<int> cnt (ALPHA, 0);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    cnt[c - 'a']++;
  }
  return cnt;
}

void solve () {
  int n, k;
  cin >> n >> k;

  auto pre = read_str(n);
  auto post = read_str(n);

  for (int i = 0; i < ALPHA - 1; i++) {
    if (pre[i] < post[i]) {
      cout << "No" << '\n';
      return;
    }

    if ((pre[i] - post[i]) % k != 0) {
      cout << "No" << '\n';
      return;
    }

    pre[i + 1] += pre[i] - post[i];
  }
  cout << "Yes" << '\n';
  return;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}