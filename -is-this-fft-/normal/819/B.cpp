#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

int arr [MAX_N];
int fixc [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  // # of things that are currently smaller-or-equal
  // and # of things that are currently bigger
  int cnt_le = 0, cnt_g = 0;

  ll dev = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= arr[i]) cnt_le++;
    else cnt_g++;

    int fixat = arr[i] - i;
    if (fixat < 0) fixat += n;
    fixc[fixat]++;

    dev += abs(arr[i] - i);
  }

  pair<ll, int> ans = make_pair(dev, 0);
  for (int i = 0; i < n; i++) {
    ans = min(ans, make_pair(dev, i));

    cnt_le -= fixc[i];
    cnt_g += fixc[i];

    cnt_g--;
    dev -= n - arr[n - i];
    dev += arr[n - i] - 1;

    dev += cnt_g;
    dev -= cnt_le;
    cnt_le++;
  }

  cout << ans.first << " " << ans.second << endl;
}