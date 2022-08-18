#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_B = 20;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

int arr [MAX_N];
int cnt [MAX_B];
int res [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    
    for (int j = 0; j < MAX_B; j++) {
      if (arr[i] & 1 << j) {
        cnt[j]++;
      }
    }
  }

  for (int j = 0; j < MAX_B; j++) {
    for (int i = 0; i < cnt[j]; i++) {
      res[i] += 1 << j;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += sq(res[i]);
  }
  cout << ans << endl;;
}