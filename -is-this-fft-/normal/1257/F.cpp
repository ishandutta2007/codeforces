#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 105;

typedef long long ll;

const ll MOD = 3006703054056749LL;

int arr [MAX_N];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < length; i++) {
    if (__builtin_popcount(arr[i] ^ arr[0]) % 2 != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  map<int, int> sol;
  for (int k = 0; k < 1 << 15; k++) {
    vector<int> record;
    bool ok = true;
    for (int i = 1; i < length; i++) {
      int sat = __builtin_popcount(k & (arr[i] ^ arr[0]));
      int need = __builtin_popcount(arr[i] ^ arr[0]) / 2;

      if (sat > need) ok = false;

      record.push_back(need - sat);
    }

    if (ok) {
      ll hsh = 0;
      for (int i = 0; i < length - 1; i++) {
        hsh *= 37;
        hsh += record[i];
        hsh %= MOD;
      }

      sol[hsh] = k;
    }
  }

  for (int k = 0; k < 1 << 30; k += 1 << 15) {
    vector<int> record;
    bool ok = true;
    for (int i = 1; i < length; i++) {
      int sat = __builtin_popcount(k & (arr[i] ^ arr[0]));
      int need = __builtin_popcount(arr[i] ^ arr[0]) / 2;

      if (sat > need) ok = false;

      record.push_back(sat);
    }

    if (ok) {
      ll hsh = 0;
      for (int i = 0; i < length - 1; i++) {
        hsh *= 37;
        hsh += record[i];
        hsh %= MOD;
      }

      if (sol.count(hsh) != 0) {
        cout << ((sol[hsh] + k) ^ arr[0]) << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}