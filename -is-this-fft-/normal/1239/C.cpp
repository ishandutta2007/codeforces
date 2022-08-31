#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> events;
set<int> cur_standing;
queue<int> tank_que;
priority_queue<int, vector<int>, greater<int>> coffee_wanters;

ll ans [MAX_N];
ll P;

void go_to_tank (int u, ll t) {
  cur_standing.insert(u);
  if (tank_que.empty()) {
    tank_que.push(u);
    events.push(make_pair(t + P, MAX_N));
  } else {
    tank_que.push(u);
  }
}

void pop_queue (ll t) {
  int u = tank_que.front();
  tank_que.pop();

  ans[u] = t;
  cur_standing.erase(u);

  if (!tank_que.empty()) {
    events.push(make_pair(t + P, MAX_N));
  }

  if (!coffee_wanters.empty() && coffee_wanters.top() < *cur_standing.begin()) {
    int n = coffee_wanters.top();
    coffee_wanters.pop();
    go_to_tank(n, t);
  }
}

void want_coffee (int u, ll t) {
  if (*cur_standing.begin() > u) {
    go_to_tank(u, t);
  } else {
    coffee_wanters.push(u);
  }
}

int main () {
  cur_standing.insert(MAX_N);

  int n;
  cin >> n >> P;

  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;

    events.push(make_pair(t, i));
  }

  while (!events.empty()) {
    auto cur = events.top();
    events.pop();

    if (cur.second != MAX_N) {
      want_coffee(cur.second, cur.first);
    } else {
      pop_queue(cur.first);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}