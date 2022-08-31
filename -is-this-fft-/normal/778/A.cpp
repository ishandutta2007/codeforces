#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 1 << 18;

int arr [MAX_N];
string s, t;

bool can (int K) {
  int n = s.size();

  vector<int> remain (n + 1, 1);
  remain[0] = 0;

  for (int i = 1; i <= K; i++) {
    remain[arr[i]] = 0;
  }

  string cur;
  for (int i = 1; i <= n; i++) {
    if (remain[i]) {
      cur.push_back(s[i - 1]);
    }
  }

  int state = 0;
  for (char c : cur) {
    if (state < (int) t.size() && c == t[state]) {
      state++;
    }
  }
  return state == (int) t.size();
}

int main () {
  cin >> s >> t;

  int n = s.size();
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int k = MAX_N; k != 0; k /= 2) {
    if (ans + k <= n && can(ans + k)) {
      ans += k;
    }
  }
  cout << ans << endl;
}