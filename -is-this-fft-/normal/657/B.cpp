#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll LIM = 1e15;

ll K;
bool valid (ll x) {
  return -K <= x && x <= K;
}

int main () {  
  int n;
  cin >> n >> K;

  vector<ll> P (n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> P[i];
  }

  vector<ll> origP = P;
  for (int i = 0; i < n; i++) {
    P[i + 1] += P[i] / 2;
    P[i] %= 2;
  }

  int fnz = -1;
  for (int i = 0; i <= n; i++) {
    if (P[i] != 0) {
      fnz = i;
      break;
    }
  }

  int ans = 0;
  ll sfx = P[n];
  if (n <= fnz && valid(origP[n] - sfx) && (origP[n] - sfx != 0)) {
    ans++;
  }
  for (int i = n - 1; i >= 0; i--) {
    sfx *= 2;
    sfx += P[i];

    if (sfx > LIM || sfx < -LIM) break;    
    if (i <= fnz && valid(origP[i] - sfx)) {
      ans++;
    }
  }

  cout << ans << endl;
}