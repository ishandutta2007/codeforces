#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_C = 20;

int solve () {
  vector<int> reqs (MAX_C, 0);

  int n;
  string s, t;

  cin >> n;
  cin >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] > t[i]) {
      return -1;
    } else if (s[i] < t[i]) {
      reqs[t[i] - 'a'] |= 1 << (s[i] - 'a');
    }
  }

  int ans = 0;
  for (int i = MAX_C - 1; i >= 0; i--) {
    if (reqs[i] & 1 << i) {
      reqs[i] -= 1 << i;
    }

    if (reqs[i] != 0) {
      int gt = 31 - __builtin_clz(reqs[i]);
      reqs[gt] |= reqs[i];
      ans++;
    }
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    cout << solve() << '\n';
  }
}