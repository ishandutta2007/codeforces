#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> divs (int x) {
  vector<int> sma;
  vector<int> big;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      sma.push_back(i);
      if (i * i != x) {
        big.push_back(x / i);
      }
    }
  }

  reverse(big.begin(), big.end());
  sma.insert(sma.end(), big.begin(), big.end());
  return sma;
}

ll tc (ll x) {
  return (x * (x - 1) * (x - 2)) / 6;
}

ll pc (ll x) {
  return (x * (x - 1)) / 2;
}

ll cntf (int L, int K) {
  auto ds = divs(K);
  ds.pop_back(); // K

  int cnt = 0;
  vector<int> sames;
  for (int i = 0; i < (int) ds.size(); i++) {
    if (ds[i] >= L) {
      cnt++;
    }

    if (__builtin_ctz(ds[i]) == __builtin_ctz(K) && 2 * ds[i] >= L) {
      sames.push_back(ds[i]);
    }
  }

  ll ans = pc(cnt);
  reverse(sames.begin(), sames.end());
  for (int sa : sames) {
    if (2 * sa + ds.back() <= K) {
      break;
    }
    
    for (int i = (int) ds.size() - 1; i >= 0; i--) {
      if (2 * sa + ds[i] <= K || ds[i] < L) {
        break;
      }
      ans++;
    }
  }
  
  if (K % 3 == 0 && K % 5 == 0 && 2 * (K / 5) >= L) {
    ans++;
  }

  return ans;
}

void solve () {
  int L, R;
  cin >> L >> R;

  ll ans = tc(R - L + 1);
  for (int k = L + 2; k <= R; k++) {
    ans -= cntf(L, k);
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