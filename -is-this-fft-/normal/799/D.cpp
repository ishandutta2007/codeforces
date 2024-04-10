#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

typedef long long llong;

using namespace std;

const int MAX_EXT = 100005;
llong exts [MAX_EXT];

int main () {
  llong a, b, h, w, extc;
  cin >> a >> b >> h >> w >> extc;

  for (int i = 0; i < extc; i++) {
    cin >> exts[i];
  }

  sort(exts, exts + extc, greater<llong> ());
  
  set<pair<llong, llong> > found;
  queue<pair<pair<llong, llong>, llong> > que;
  que.push(make_pair(make_pair(h, w), 0));

  while (!que.empty()) {
    pair<pair<llong, llong>, llong> qtop = que.front();
    que.pop();

    if ((qtop.first.first >= a && qtop.first.second >= b) ||
        (qtop.first.first >= b && qtop.first.second >= a)) {
      cout << qtop.second << endl;
      return 0;
    }
    
    if (qtop.first.first < max(a, b)) {
      if (found.count(make_pair(qtop.first.first * exts[qtop.second],
                                qtop.first.second)) == 0) {
        found.insert(make_pair(qtop.first.first * exts[qtop.second],
                               qtop.first.second));
      
        que.push(make_pair(make_pair(qtop.first.first * exts[qtop.second],
                                     qtop.first.second),
                           qtop.second + 1));
      }
    }

    if (qtop.first.second < max(a, b)) {
      if (found.count(make_pair(qtop.first.first,
                                qtop.first.second * exts[qtop.second])) == 0) {
        found.insert(make_pair(qtop.first.first,
                               qtop.first.second * exts[qtop.second]));
        
        que.push(make_pair(make_pair(qtop.first.first,
                                     qtop.first.second * exts[qtop.second]),
                           qtop.second + 1));
      }
    }
  }

  cout << -1 << endl;
}