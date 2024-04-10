#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, K;
  cin >> n >> K;

  ll cnt = 0;
  ll sum = 0;
  ll rem = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;

    ll delta = sum - cnt * (n - rem - (cnt + 1)) * x;
    if (delta < K) {
      cout << i + 1 << '\n';
      rem++;
      continue;
    }

    sum += x * cnt;
    cnt++;
  }
}