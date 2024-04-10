#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1e5 + 5;

typedef long long ll;

struct Event {
  ll time, idx;

  Event (ll _time = 0, int _idx = 0)
    : time(_time), idx(_idx) {}
};

bool operator< (Event p, Event q) {
  return make_pair(p.time, p.idx) < make_pair(q.time, q.idx);
}

ll time_at [MAX_N];
int from [MAX_N];
int to [MAX_N];
ll ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int queryc, height;
  cin >> queryc >> height;
  
  set<Event> Q;
  for (int i = 0; i < queryc; i++) {
    cin >> time_at[i] >> from[i] >> to[i];
    Q.insert(Event(time_at[i], i));
  }

  ordered_set<pair<int, int>> wait;
  ordered_set<pair<int, int>> lift;
  int moving = 0;
  int cfloor = 1;
  int last = 0;
  while (!Q.empty()) {    
    Event cur = *Q.begin();
    Q.erase(Q.begin());

    cfloor += (cur.time - last) * moving;
    last = cur.time;
    
    if (cur.idx != -1) {
      wait.insert(make_pair(from[cur.idx], cur.idx));
    }
    
    if (Q.empty() || Q.begin()->time != cur.time) {
      // move statuses of people
      vector<int> to_lift;
      for (auto it = wait.upper_bound(make_pair(cfloor, -1));
           it != wait.end() && it->first == cfloor; it++) {
        to_lift.push_back(it->second);
      }

      for (int u : to_lift) {
        wait.erase(make_pair(from[u], u));
        lift.insert(make_pair(to[u], u));
      }
      
      vector<int> to_finish;
      for (auto it = lift.upper_bound(make_pair(cfloor, -1));
           it != lift.end() && it->first == cfloor; it++) {
        to_finish.push_back(it->second);
      }

      for (int u : to_finish) {
        lift.erase(make_pair(to[u], u));
        ans[u] = cur.time;
      }
      
      // move the lift
      int pri_dn = wait.order_of_key(make_pair(cfloor, -1))
        + lift.order_of_key(make_pair(cfloor, -1));
      int pri_up = (int) wait.size() + (int) lift.size() - pri_dn;

      if (pri_dn + pri_up == 0) {
        moving = 0;
      } else {
        int nxtv;
        if (pri_up >= pri_dn) {
          moving = 1;
          nxtv = MAX_N;

          auto wub = wait.upper_bound(make_pair(cfloor, -1));
          if (wub != wait.end()) {
            nxtv = min(wub->first, nxtv); 
          }

          auto lub = lift.upper_bound(make_pair(cfloor, -1));
          if (lub != lift.end()) {
            nxtv = min(lub->first, nxtv);
          }
        } else {
          moving = -1;
          nxtv = -1;

          auto wub = wait.upper_bound(make_pair(cfloor, -1));
          if (wub != wait.begin()) {
            nxtv = max(prev(wub)->first, nxtv); 
          }

          auto lub = lift.upper_bound(make_pair(cfloor, -1));
          if (lub != lift.begin()) {
            nxtv = max(prev(lub)->first, nxtv);
          }          
        }

        ll nxtt = cur.time + abs(nxtv - cfloor);
        if (Q.empty() || Q.begin()->time > nxtt) {
          Q.insert(Event(nxtt, -1));
        }
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << '\n';
  }
}