#include <iostream>

using namespace std;

const int MAX_P = 60000;
const int MAX_LG = 3;

int precalc [MAX_P];

int solve (int x, int d = 0) {
  if (x < MAX_P) {
    return precalc[x];
  }

  int ans = x - 1;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans = min(ans, 1 + solve(i));
    }
  }

  if (d == MAX_LG) {
    return ans;
  }
  return min(ans, 1 + solve(x - 1, d + 1));
}

void solve () {
  int x;
  cin >> x;

  cout << solve(x) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 1; i < MAX_P; i++) {
    precalc[i] = i;
  }

  precalc[1] = 0;
  for (int i = 2; i < MAX_P; i++) {
    precalc[i] = min(precalc[i], precalc[i - 1] + 1);
    for (int j = 2 * i; j < MAX_P; j += i) {
      if (j != i) {
        precalc[j] = min(precalc[j], 1 + precalc[i]);
      }
    }
  }
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}