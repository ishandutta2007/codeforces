#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];
ll cum [MAX_N];
ll ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int candyc, perday;
  cin >> candyc >> perday;

  for (int i = 0; i < candyc; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + candyc);

  cum[0] = arr[0];
  for (int i = 1; i < candyc; i++) {
    cum[i] = cum[i - 1] + arr[i];
  }

  for (int i = 0; i < candyc; i++) {
    if (i < perday) {
      ans[i] = cum[i];
    } else {
      ans[i] = ans[i - perday] + cum[i];
    }
  }

  for (int i = 0; i < candyc; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}