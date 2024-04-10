#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n, a[M], b[M];

void read() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[a[i]] = i;
  }
}

void kill() {
  int cur = 1, len = 1;
  int ans = 1;
  while (cur != n) {
    if (b[cur + 1] > b[cur])
      ++len;
    else
      len = 1;
    ++cur;
    ans = max(ans, len);
  }

  cout << n - ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
  return 0;
}