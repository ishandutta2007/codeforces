#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


const int M = 400;

int n;
vector<int> a[M];

void read() {
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    --x;
    a[x].push_back(i);
  }
}

int fun(vector<int> a, vector<int> b) {
  if (a[0] > b[0])
    swap(a, b);
  if (b[1] < a[1])
    return 2;
  if (a[1] < b[0])
    return 0;
  return 1;
}

void kill() {
  int ans = 0;
  for (int i = 0; i < n; ++i)
    sort(all(a[i]));

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      ans += fun(a[i], a[j]);
    }

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}