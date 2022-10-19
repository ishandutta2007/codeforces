#include <bits/stdc++.h>

using namespace std;

typedef long double ll;
typedef long double ld;

const int M = 1e4 + 10;

ll cnt[M];
ll sum[M];
int n, a[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
}

void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      cnt[a[j] - a[i]]++;
}

void finish() {
  for (int i = M - 2; i >= 0; --i)
    sum[i] = sum[i + 1] + cnt[i + 1];

  ll ans = 0;

  for (int a = 0; a < M; ++a)
    for (int b = 0; a + b + 1 < M; ++b)
      ans += cnt[a] * cnt[b] * sum[a + b];

  ll den = n * (n - 1) / 2;
  den = den * den * den;

  ld tans = (ld(ans)) / den;
  cout << tans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
  finish();
}