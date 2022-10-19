#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

int n, a[M];

void read() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = 0;
}

bool check(int k) {
  for (int i = 1; i + k <= n; ++i)
    if (a[i] != a[i + k])
      return false;
  return true;
}

void kill() {
  for (int i = n; i >= 1; --i)
    a[i] -= a[i - 1];
  vector<int> ans;
  for (int k = 1; k <= n; ++k)
    if (check(k))
      ans.push_back(k);
  cout << ans.size() << "\n";
  for (int x : ans)
    cout << x << " ";
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}