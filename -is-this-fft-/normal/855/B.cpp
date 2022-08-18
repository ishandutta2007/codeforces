#include <iostream>

using namespace std;

const int MAX_N = 100005;

typedef long long ll;

ll prefmax [MAX_N];
ll suffmax [MAX_N];
ll arr [MAX_N];

const ll INF = 3e18 + 5;

int main () {
  int length;
  cin >> length;

  ll p, q, r;
  cin >> p >> q >> r;
  
  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  if (p >= 0) {
    prefmax[0] = -INF;
  } else {
    prefmax[0] = INF;
  }

  if (r >= 0) {
    suffmax[length + 1] = -INF;
  } else{
    suffmax[length + 1] = INF;
  }
    
  for (int i = 1; i <= length; i++) {
    if (p >= 0) {
      prefmax[i] = max(arr[i], prefmax[i - 1]);
    } else {
      prefmax[i] = min(arr[i], prefmax[i - 1]);
    }      
  }

  for (int i = length; i >= 1; i--) {
    if (r >= 0) {
      suffmax[i] = max(arr[i], suffmax[i + 1]);
    } else {
      suffmax[i] = min(arr[i], suffmax[i + 1]);
    }      
  }

  ll ans = -INF;
  for (int i = 1; i <= length; i++) {
    ans = max(ans, arr[i] * q + prefmax[i] * p + suffmax[i] * r);
  }

  cout << ans << endl;
}