#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

int n, s;
int a[M], cnt[M];

void read() {
  cin >> n >> s;
  --s;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}


void answer(int x) {
  cout << x << endl;
  exit(0);
}

void kill() {
  int bon = a[s] != 0 ? 1 : 0;

  if (n == 1)
    answer(bon);

  for (int i = 0; i < n; ++i)
    if (i != s)
      cnt[a[i]]++;

  int up = cnt[0];
  int rest = accumulate(cnt + 1, cnt + n, 0);
  int missing = 0;
  int best = n - 1;

  for (int d = 1; d <= n - 1; ++d) {
    if (cnt[d] == 0)
      ++missing;
    rest -= cnt[d];

    int cur = max(missing, up + rest);
    best = min(best, cur);
  }

  answer(best + bon);
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}