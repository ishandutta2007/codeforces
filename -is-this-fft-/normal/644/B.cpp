#include <iostream>
#include <vector>
#include <queue>
#include <utility>

typedef long long llong;

using namespace std;

struct query {
  int index;
  llong entryt, proct;

  query () {
    index = -1;
    entryt = -1;
    proct = -1;
  }

  query (int ii, llong ie) {
    index = ii;
    entryt = ie;
    proct = 0;
  }

  query (int ii, llong ie, llong ip) {
    index = ii;
    entryt = ie;
    proct = ip;
  }
};

bool operator< (query p, query q) {
  if (p.entryt == q.entryt) {
    return p.proct > q.proct;
  } else {
    return p.entryt > q.entryt;
  }
}

int main () {
  int queryc, maxque;
  cin >> queryc >> maxque;

  priority_queue<query> events;
  for (int i = 0; i < queryc; i++) {
    llong entrytime, proctime;
    cin >> entrytime >> proctime;

    events.push(query(i, entrytime, proctime));
  }

  queue<query> curque;
  vector<llong> ans (queryc);
  bool busy = false;
  while (!events.empty()) {
    query qtop = events.top();
    events.pop();

    if (qtop.proct == 0) { /* A process has finished */
      ans[qtop.index] = qtop.entryt;

      if (!curque.empty()) {
	query next = curque.front();
	events.push(query(next.index, qtop.entryt + next.proct));
	curque.pop();
      } else {
	busy = false;
      }
    } else { /* A new process has requested access */
      if (curque.size() == 0 && !busy) {
	events.push(query(qtop.index, qtop.entryt + qtop.proct));
	busy = true;
      } else if (curque.size() < maxque) {
	curque.push(qtop);
      } else {
	ans[qtop.index] = -1; /* :( */
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << (i == queryc - 1 ? '\n' : ' ');
  }
}