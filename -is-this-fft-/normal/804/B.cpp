#include <iostream>
#include <string>

typedef long long llong;

const int MOD = 1000000007;

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  string arr;
  cin >> arr;

  llong ans = 0, bcount = 0;
  for (int i = (int) arr.size() - 1; i >= 0; i--) {
    if (arr[i] == 'b') {
      bcount++;
      bcount %= MOD;
    } else {
      ans += bcount;
      ans %= MOD;
    
      bcount *= 2;
      bcount %= MOD;
    }
  }

  cout << ans << endl;
}