#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

vector<int> d[M];

void pre() {
  for (int i = 1; i < M; ++i)
    for (int j = i; j < M; j += i)
      d[j].push_back(i);
  int mx = 0;
  for (int i = 0; i < M; ++i)
    mx = max(mx, (int) d[i].size());
  //cerr << "mx = " << mx << "\n";
}

int n, x[M];

void read() {
  cin >> n;
  n /= 2;

  vector<int> ans = {0};

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    int bestA = -1, bestB = -1;
    int last = ans.back();

    for (int y : d[x]) {
      int a = y, b = x / y;
      if (a >= b) continue;
      if ((b - a) % 2 == 1) continue;

      int A = (a + b) / 2;
      int B = (b - a) / 2;

      if (B > last) {
        if (bestA == -1 || A < bestA) {
          bestA = A;
          bestB = B;
        }
      }
    }

    if (bestA == -1) {
      cout << "No\n";
      return;
    }

    ans.push_back(bestB);
    ans.push_back(bestA);
  }

  cout << "Yes\n";
  n *= 2;
  for (int i = 0; i < n; ++i) {
    ll x = ans[i];
    ll y = ans[i + 1];
    cout << y * y - x * x << " ";
  }
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  pre();

  read();
}