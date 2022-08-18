#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

pair<int, int> ask (int idx) {
  idx++;
  cout << "? " << idx << endl;
  
  int val, nxt;
  cin >> val >> nxt;
  if (val == -1 && nxt == -1) {
    exit(0);
  }
  return make_pair(val, nxt - 1);
}

void report (int ans) {
  cout << "! " << ans << endl;
  exit(0);
}

int rng () {
  int ans = 0;
  for (int i = 0; i < 20; i++) {
    ans *= 2;
    ans += rand() % 2;
  }
  return ans;
}

int main () {
  srand(time(NULL));
  
  int length, head, target;
  cin >> length >> head >> target;
  head--;

  pair<int, int> best = ask(head);
  for (int i = 0; i < 1000; i++) {
    int idx = rng() % length;
    pair<int, int> cur = ask(idx);
    if (cur.first < target) {
      best = max(best, cur);
    }
  }

  while (true) {
    if (best.first < target) {
      if (best.second == -2) {
        report(-1);
      }
      best = ask(best.second);
    } else {
      report(best.first);
    }
  }
}