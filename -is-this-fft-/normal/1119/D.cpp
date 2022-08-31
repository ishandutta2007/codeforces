#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;

struct Event {
  int type;
  ll moment;
  int id;

  Event (ll _moment) {
    type = 0;
    moment = _moment;
    id = -1;
  }

  Event (ll _moment, ll _id) {
    type = 1;
    moment = _moment;
    id = _id;
  }
};

bool operator< (Event e, Event f) {
  return e.moment < f.moment;
}

ll arr [MAX_N];
ll ans [MAX_N];

int main () {
  int stringc;
  cin >> stringc;

  for (int i = 0; i < stringc; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + stringc);

  int queryc;
  cin >> queryc;

  vector<Event> events;
  for (int i = 0; i < queryc; i++) {
    ll l, r;
    cin >> l >> r;

    events.push_back(Event(r - l + 1, i));
  }

  for (int i = 0; i < stringc - 1; i++) {
    events.push_back(Event(abs(arr[i + 1] - arr[i])));
  }

  sort(events.begin(), events.end());
  ll curAns = 0;
  ll overlap = 0;
  ll lastEvent = 0;
  for (Event e : events) {
    curAns += (e.moment - lastEvent) * (stringc - overlap);

    if (e.type == 1) {
      ans[e.id] = curAns;
    } else {
      overlap++;
    }

    lastEvent = e.moment;
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}