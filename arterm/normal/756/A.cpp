#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 200200;

int n;
int p[M];
int b[M];
bool u[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
}

void kill() {
  int ans = 0;
  int cnt = 0;

  for (int i = 0; i < n; ++i)
    if (!u[i]) {
      int x = i;
      while (!u[x]) {
        u[x] = true;
        x = p[x];
      }
      ++cnt;
    }


  int sum = accumulate(b, b + n, 0) % 2;
  
  ans = (cnt == 1 ? 0 : cnt) + (sum % 2 == 1 ? 0 : 1);

  cout << ans << endl;
}


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}