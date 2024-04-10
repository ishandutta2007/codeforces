#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 500500;

int n, a, b, t;
int l[M], r[M];
string s;

void read() {
  cin >> n >> a >> b >> t;
  cin >> s;
}

int cost(int i) {
  return s[i] == 'w' ? b + 1 : 1;
}

void pre() {
  l[0] = cost(0);
  for (int i = 1; i < n; ++i)
    l[i] = l[i - 1] + a + cost(i);

  l[n] = t + 1;

  r[0] = 0;
  for (int i = 1; i <= n; ++i)
    r[i] = r[i - 1] + a + cost(n - i);

  r[n + 1] = t + 1;

  /*for (int i = 0; i <= n; ++i)
    cerr << l[i] << " ";
  cerr << endl;

  for (int i = 0; i <= n + 1; ++i)
    cerr << r[i] << " ";
  cerr << endl;
  cerr << endl;
  */
}

int kill() {
  int ans = 0;

  int i = 0;
  while (l[i] <= t)
    ++i;

  ans = max(ans, i);

  int j = 0;

  while (i > 0) {
    while (i + j < n + 1 && r[j] + (i - 1) * a + l[i - 1] <= t)
      ++j;
    if (j > 0 && r[j - 1] + (i - 1) * a + l[i - 1] <= t)
      ans = max(ans, i + j - 1);
    --i;
  }

  return ans;
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  int ans = 0;
  pre();
  ans = max(ans, kill());

  reverse(s.begin() + 1, s.end());
  pre();
  ans = max(ans, kill());

  cout << ans << endl;
  return 0;
}