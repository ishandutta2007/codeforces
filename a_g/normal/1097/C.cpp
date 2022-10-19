#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int open[N];
int close[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int any = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int cur = 0;
    int low = 0;
    for (char c: s) {
      if (c == '(') cur++;
      else cur--;
      low = min(low, cur);
    }
    if (cur == 0) {
      if (low == 0) any++;
    }
    if (cur > 0) {
      if (low == 0) {
        open[cur]++;
      }
    }
    if (cur < 0) {
      if (low == cur) {
        close[-cur]++;
      }
    }
  }

  int ans = any/2;
  for (int i = 1; i < N; i++) {
    ans += min(open[i], close[i]);
  }
  cout << ans << '\n';
}