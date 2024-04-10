#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

pair<int, int> arr [MAX_N]; // <pos, weight>

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n);

  // <pos, arg>
  // if arg is positive then we have an opening with weight arg
  // otherwise we have a closing with max -mx
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> events;
  for (int i = 0; i < n; i++) {
    events.push(make_pair(arr[i].first - arr[i].second, arr[i].second));
  }

  int ans = 0;
  while (!events.empty()) {
    auto cur = events.top();
    events.pop();

    int pos = cur.first;
    if (cur.second > 0) {
      int weight = cur.second;
      events.push(make_pair(pos + 2 * weight, -(ans + 1)));
    } else {
      int mx = -cur.second;
      ans = max(ans, mx);
    }
  }

  cout << ans << endl;
}