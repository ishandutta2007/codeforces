#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 500500;

int n, r;
ll a[M];
ll sum = 0;

void read() {
  cin >> n;
  cin >> r;

  n = (1 << n);
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  cout.precision(10);
  cout << fixed;

  cout << ld(sum) / n << "\n";
  for (int i = 0; i < r; ++i) {
    int x, to;
    cin >> x >> to;
    sum -= a[x];
    a[x] = to;
    sum += to;
    cout << ld(sum) / n << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();

}