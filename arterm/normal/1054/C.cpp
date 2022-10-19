#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

int l[M], r[M];
int n;
bool u[M];
int a[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> l[i];
  for (int j = 0; j < n; ++j)
    cin >> r[j];
}

void kill() {
  int last = n;

  while (true) {
    int cnt = 0;

    for (int i = 0; i < n; ++i)
      if (!u[i] && (l[i] == 0 && r[i] == 0)) {
        ++cnt;
      }

    if (cnt == 0) {
      for (int i = 0; i < n; ++i)
        if (!u[i]) {
          cout << "NO\n";
          return;
        }

      cout << "YES\n";
      for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
      cout << "\n";
      return;
    }

    int fr = cnt, fl = 0;

    for (int i = 0; i < n; ++i)
      if (!u[i]) {
        if (l[i] == 0 && r[i] == 0) {
          u[i] = true;
          fl++;
          fr--;
          a[i] = last;
        } else {
          l[i] -= fl;
          r[i] -= fr;
        }
      }
    --last;
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}