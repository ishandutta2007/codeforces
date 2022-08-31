#include <iostream>
#include <queue>

typedef long long llong;

const int MAX_FLIGHT = 300005;

using namespace std;

llong cost [MAX_FLIGHT], depart [MAX_FLIGHT];

int main () {
  ios::sync_with_stdio(false);
  
  int flightc, delay;
  cin >> flightc >> delay;

  for (int i = 1; i <= flightc; i++) {
    cin >> cost[i];
  }

  llong cur_cost = 0, ans = 0;
  priority_queue<pair<int, int> > que;
  for (int i = 1; i <= flightc + delay; i++) {
    if (i <= flightc) {
      /* add the current flight */
      que.push(make_pair(cost[i], i));
      cur_cost += cost[i];
    }

    if (i > delay) {
      depart[que.top().second] = i;
      cur_cost -= que.top().first;
      que.pop();
    }

    ans += cur_cost;
  }

  cout << ans << endl;
  for (int i = 1; i <= flightc; i++) {
    cout << depart[i] << ' ';
  }
  cout << endl;
}