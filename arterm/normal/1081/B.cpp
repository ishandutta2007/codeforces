#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int n, a[M], cnt[M];
int mp[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x = (n - x);
    a[i] = x;
    cnt[x]++;
  }
}

void kill() {
  for (int i = 1; i <= n; ++i)
    if (cnt[i] % i != 0) {
      cout << "Impossible\n";
      return;
    }
  cout << "Possible\n";
  int last = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    if (cnt[x] % x == 0) {
      ++last;
      mp[x] = last;
    }
    cout << mp[x] << " ";
    cnt[x]--;
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}