#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 300005;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  ll length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    ll x;
    cin >> x;

    arr[i] = __builtin_popcountll(x);
  }

  ll zeroc = 1, onec = 0;
  int cur = 0;
  for (int i = 0; i < length; i++) {
    cur += arr[i];
    cur %= 2;

    if (cur == 0) {
      zeroc++;
    } else {
      onec++;
    }
  }

  ll ans = zeroc * (zeroc - 1) / 2 + onec * (onec - 1) / 2;

  for (int i = 0; i < length; i++) {
    int cur_sum = arr[i];
    int cur_max = arr[i];

    if (cur_sum % 2 == 0) {
      ans--;
    }
    
    for (int j = i - 1; j >= i - 130 && j >= 0; j--) {
      cur_sum += arr[j];
      cur_max = max(cur_max, arr[j]);

      if (2 * cur_max > cur_sum && cur_sum % 2 == 0) {
        ans--;
      }
    }
  }

  cout << ans << endl;
}