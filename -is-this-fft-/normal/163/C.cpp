#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

struct Event {
  ld moment;
  int type;

  Event () {}
  Event (ld _moment, int _type) : moment(_moment), type(_type) {}
};

bool operator< (Event e, Event f) {
  return e.moment < f.moment;
}

const int MAX_N = 100005;
ld ans [MAX_N];

int main () {
  int candyc;
  cin >> candyc;

  ld l, v1, v2;
  cin >> l >> v1 >> v2;
  
  vector<int> candies (candyc);
  for (int i = 0; i < candyc; i++) {
    cin >> candies[i];
  }

  ld distance = (l * v2) / (v1 + v2);
  vector<Event> events;

  int curCandyc = 0;
  for (int i = 0; i < candyc; i++) {
    if ((ld) candies[i] - distance < 0) {
      curCandyc++;
      events.push_back(Event(2 * l + (ld) candies[i] - distance, 1));
    } else {
      events.push_back(Event((ld) candies[i] - distance, 1));
    }

    events.push_back(Event(candies[i], -1));
  }
  sort(events.begin(), events.end());

  ld last = 0;
  for (Event e : events) {
    ans[curCandyc] += e.moment - last;
    curCandyc += e.type;
    last = e.moment;
  }

  ans[curCandyc] += 2 * l - last;

  for (int i = 0; i <= candyc; i++) {
    cout << fixed << setprecision(18) << ans[i] / (2 * l) << '\n';
  }
}