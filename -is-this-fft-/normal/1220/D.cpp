#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 200005;

int cnt [70];
ll arr [MAX_N];
int nts [MAX_N];

int ntwos (ll x) {
  int ans = 0;
  while (x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    ll x;
    cin >> arr[i];
    x = arr[i];
    nts[i] = ntwos(x);
    cnt[nts[i]]++;
  }

  pair<int, int> ans = make_pair(length, -1);
  for (int i = 0; i < 70; i++) {
    ans = min(ans, make_pair(length - cnt[i], i));
  }

  cout << ans.first << endl;
  for (int i = 0; i < length; i++) {
    if (nts[i] != ans.second) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}