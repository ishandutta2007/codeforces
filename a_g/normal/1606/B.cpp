#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    ll good = 1;
    ll steps = 0;
    while (good < k) {
      good *= 2;
      steps += 1;
    }
    if (good < n) {
      steps += (n-good-1)/k+1;
    }
    cout << steps << '\n';
  }
}