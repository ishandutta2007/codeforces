#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 7005;

typedef long long ll;

pair<ll, ll> arr [MAX_N];
int taken [MAX_N];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i].first;
  }

  for (int i = 0; i < length; i++) {
    cin >> arr[i].second;
  }

  vector<int> ips;
  sort(arr, arr + length);
  for (int i = 0; i < length - 1; i++) {
    if (arr[i].first == arr[i + 1].first) {
      ips.push_back(i);
    }
  }

  ll ans = 0;
  for (int u : ips) {
    for (int i = 0; i < length; i++) {
      if ((arr[i].first | arr[u].first) == arr[u].first) {
        taken[i] = 1;
      }
    }
  }

  for (int i = 0; i < length; i++) {
    if (taken[i]) {
      ans += arr[i].second;
    }
  }
  cout << ans << endl;
}