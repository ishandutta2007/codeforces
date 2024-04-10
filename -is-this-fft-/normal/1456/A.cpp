#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 2e9 + 42412;

int arr [MAX_N];
int sfx [MAX_N];

void solve () {
  int n, P, K;
  cin >> n >> P >> K;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    arr[i] = c - '0';
  }

  int X, Y;
  cin >> X >> Y;

  for (int i = n - 1; i >= 0; i--) {
    if (i + K < n) {
      sfx[i] = sfx[i + K];
    } else {
      sfx[i] = 0;
    }

    sfx[i] += X * !arr[i];
  }

  int ans = INF;
  for (int i = 0; i + P - 1 < n; i++) {
    ans = min(ans, Y * i + sfx[i + P - 1]);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}