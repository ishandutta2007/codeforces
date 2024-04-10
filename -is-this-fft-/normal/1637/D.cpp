#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 105;
const int MAX_A = 3e4 + 5;

int a [MAX_N], b [MAX_N];
bool can [MAX_A];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) swap(a[i], b[i]);
  }

  int tota = 0, totb = 0;
  for (int i = 0; i < n; i++) {
    tota += a[i];
    totb += b[i];
  }
  
  for (int i = 0; i < MAX_A; i++) {
    can[i] = 0;
  }

  can[tota] = 1;
  for (int i = 0; i < n; i++) {
    int add = b[i] - a[i];
    for (int j = MAX_A - add - 1; j >= 0; j--) {
      can[j + add] |= can[j];
    }
  }

  int best = tota;
  for (int i = 0; i < MAX_A; i++) {
    if (can[i]) {
      if (abs(2 * i - tota - totb) < abs(2 * best - tota - totb)) {
        best = i;
      }
    }
  }

  int suma = best, sumb = tota + totb - best;
  ll ans = 0;
  ans += suma * suma;
  ans += sumb * sumb;
  for (int i = 0; i < n; i++) {
    ans += (n - 2) * a[i] * a[i];
    ans += (n - 2) * b[i] * b[i];
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}