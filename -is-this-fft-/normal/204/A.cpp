#include <iostream>

using namespace std;

typedef long long ll;

ll solve (ll x) {
  if (x < 10) return x;

  ll ans = x / 10;
  ll lst = x % 10;
  ll fst = x;
  while (fst >= 10) {
    fst /= 10;
  }

  if (lst < fst) {
    ans--;
  }

  return ans + 9;
}

int main () {
  ll L, R;
  cin >> L >> R;

  cout << solve(R) - solve(L - 1) << endl;
}