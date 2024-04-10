#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;
const int T = 150150;

int q[M], qs = T, qf = T;

int gcd(int x, int y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}


int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> p;

  int m = n;

  for (int i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      p.push_back(i);
      while (m % i == 0) {
        m /= i;
      }
    }
  }

  if (m > 1) {
    p.push_back(m);
  }

  sort(all(p), greater<int>());

  int mod = p.back();
  p.pop_back();

  if (p.empty()) {
    cout << "NO\n";
    return 0;
  }

  m = n;
  while (m % mod == 0) {
    m /= mod;
  }

  vector<int> ans;

  int cur = 0;
  while (cur % mod != mod - 1) {
    cur += m;
    ans.push_back(m);
  }

  assert(n - 1 >= cur);
  if (n - 1 > cur)
    ans.push_back((n - 1 - cur));

  cout << "YES\n";
  cout << ans.size() << "\n";
  for (int x : ans) {
    int y = n;
    int g = gcd(x, y);
    assert(g > 1);
    cout << x / g << " " << y / g << "\n";
  }
}