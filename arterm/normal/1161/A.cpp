#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int inf = 1e9;

int n;
int last[M];
int first[M];
int x[M];

void read() {
  cin >> n;
  fill(last, last + n, -1);
  fill(first, first + n, inf);

  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x[i];
    --x[i];
    last[x[i]] = i;
  }

  for (int i = k - 1; i >= 0; --i) {
    first[x[i]] = i;
  }
}

void kill() {
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (last[i] == -1) {
      ++ans;
      //cerr << i + 1 << " " << i + 1 << "\n";
    }

  for (int i = 0; i < n; ++i)
    for (int j : {i - 1, i + 1}) {
      if (0 <= j && j < n) {
        if (last[j] <= first[i]) {
          ++ans;
          //cerr << i + 1 << " " << j + 1 << "\n";
        }
      }
    }

  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}