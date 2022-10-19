#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 6e6 + 10;

vector<int> a, b;


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i < M; ++i) {
    if (i % 6 == 0)
      continue;
    if (i % 2 == 0)
      a.push_back(i);
    if (i % 3 == 0)
      b.push_back(i);
  }

  a.resize(n);
  b.resize(m);

  int k = 0;
  int mx = 0;
  if (!a.empty())
    mx = max(mx, a.back());
  if (!b.empty())
    mx = max(mx, b.back());

  int ans = mx; 

  for (int i = 0; !a.empty() || !b.empty(); ++i) {
    k += 6;
    if (a.empty())
      b.pop_back();
    else if (b.empty())
      a.pop_back();
    else if (a.back() > b.back())
      a.pop_back();
    else
      b.pop_back();
    int mx = 0;
    if (!a.empty())
      mx = max(mx, a.back());
    if (!b.empty())
      mx = max(mx, b.back());

    ans = min(ans, max(k, mx));
  }

  cout << ans << endl;
}