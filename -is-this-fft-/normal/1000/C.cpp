#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long llong;

const int MAX_N = 200005;

typedef pair<llong, llong> event;

llong ans [MAX_N];

int main () {
  int segc;
  cin >> segc;

  vector<event> events;
  for (int i = 0; i < segc; i++) {
    llong l, r;
    cin >> l >> r;

    events.push_back(make_pair(l, 1));
    events.push_back(make_pair(r + 1, -1));
  }

  sort(events.begin(), events.end());

  llong last = -1;
  int cur_cnt = 0;

  for (event e : events) {
    ans[cur_cnt] += e.first - last;
    last = e.first;
    cur_cnt += e.second;
  }

  for (int i = 1; i <= segc; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}