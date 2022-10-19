#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

int n, k;
string s;
int sum[M];

void read() {
  cin >> n >> k;
  cin >> s;

  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int x = s[i - 1] == '0' ? 1 : 0;
    sum[i] = x + sum[i - 1];
  }
}

bool pos(int d) {
  for (int i = 1; i <= n; ++i)
    if (s[i - 1] == '0') {
      int cnt = sum[min(n, i + d)] - sum[max(i - d - 1, 0)];
      if (cnt >= k + 1)
        return true;
    }
  return false;
}

void kill() {
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (pos(m))
      r = m;
    else
      l = m + 1;
  }
  
  cout << l << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}