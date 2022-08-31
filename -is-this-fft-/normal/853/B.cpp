#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

typedef long long llong;

const int MAX_PERSON = 100005;
const int MAX_TIME = 1000020;

using namespace std;

struct ticket {
  llong type, city, id, time;
  llong cost;

  ticket (llong _type, llong _city, llong _id, llong _time, llong _cost) {
    type = _type;
    city = _city;
    id = _id;
    time = _time;
    cost = _cost;
  }
};

bool operator< (ticket p, ticket q) {
  if (p.cost == q.cost) {
    return p.id < q.id;
  } else {
    return p.cost < q.cost;
  }
}

bool bytime (ticket p, ticket q) {
  if (p.time == q.time) {
    return p < q;
  } else {
    return p.time < q.time;
  }
}

llong bestarr [MAX_TIME], bestdep [MAX_TIME];
llong best_arr_c [MAX_PERSON], best_dep_c [MAX_PERSON];

int main () {
  for (llong i = 0; i < MAX_PERSON; i++) {
    best_arr_c[i] = -1;
    best_dep_c[i] = -1;
  }
  
  ios::sync_with_stdio(false);
  
  llong cityc, flightc, interval;
  cin >> cityc >> flightc >> interval;
  
  deque<ticket> arrivals, departs;
  for (llong i = 0; i < flightc; i++) {
    llong day, start, finish, cost;
    cin >> day >> start >> finish >> cost;

    if (finish == 0) {
      arrivals.push_back(ticket(0, start, i, day, cost));
    } else {
      departs.push_back(ticket(1, finish, i, day, cost));
    }
  }

  sort(arrivals.begin(), arrivals.end(), bytime);
  sort(departs.begin(), departs.end(), bytime);

  llong arr_c = 0;
  set<llong> visited_a;
  for (llong i = 0; i < MAX_TIME; i++) {
    while (!arrivals.empty() && arrivals.front().time == i) {
      if (best_arr_c[arrivals.front().city] == -1) {
        best_arr_c[arrivals.front().city] = arrivals.front().cost;
        arr_c += arrivals.front().cost;
        visited_a.insert(arrivals.front().city);
      } else if (best_arr_c[arrivals.front().city] > arrivals.front().cost) {
        arr_c -= best_arr_c[arrivals.front().city];
        best_arr_c[arrivals.front().city] = arrivals.front().cost;
        arr_c += best_arr_c[arrivals.front().city];
      }

      arrivals.pop_front();
    }

    if (visited_a.size() == cityc) {
      bestarr[i] = arr_c;
    } else {
      bestarr[i] = -1;
    }
  }
  
  llong dep_c = 0;
  set<llong> visited_c;
  for (llong i = MAX_TIME - 1; i >= 0; i--) {
    while (!departs.empty() && departs.back().time == i) {
      if (best_dep_c[departs.back().city] == -1) {
        best_dep_c[departs.back().city] = departs.back().cost;
        dep_c += departs.back().cost;
        visited_c.insert(departs.back().city);
      } else if (best_dep_c[departs.back().city] > departs.back().cost) {
        dep_c -= best_dep_c[departs.back().city];
        best_dep_c[departs.back().city] = departs.back().cost;
        dep_c += best_dep_c[departs.back().city];
      }

      departs.pop_back();
    }

    if (visited_c.size() == cityc) {
      bestdep[i] = dep_c;
    } else {
      bestdep[i] = -1;
    }
  }

  llong ans = 1000000000000000000LL;
  for (llong i = 0; i < MAX_TIME - interval - 1; i++) {
    if (bestarr[i] != -1 && bestdep[i + interval + 1] != -1) {
      ans = min(ans, bestarr[i] + bestdep[i + interval + 1]);
    }
  }

  if (ans == 1000000000000000000LL) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}