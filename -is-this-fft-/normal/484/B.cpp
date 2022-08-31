#include <iostream>

using namespace std;

const int MAX_A = 2e6 + 5;

bool exists [MAX_A];
int grp [MAX_A];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    exists[x] = 1;
    grp[x] = x;
  }

  for (int i = 1; i < MAX_A; i++) {
    grp[i] = max(grp[i], grp[i - 1]);
  }

  int ans = 0;
  for (int i = 1; i < MAX_A; i++) {
    if (!exists[i]) {
      continue;
    }

    for (int j = 2 * i; j < MAX_A; j += i) {
      int mx = grp[j - 1];
      if (mx < j - i) {
        continue;
      }

      ans = max(ans, mx - (j - i));
    }
  }

  cout << ans << endl;
}