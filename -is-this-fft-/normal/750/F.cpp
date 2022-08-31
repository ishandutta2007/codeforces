#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

const int MAX_N = 128;

vector<int> adj [MAX_N];

void ask (int u) {
  cout << "? " << u << '\n';

  int k;
  cin >> k;
  adj[u] = vector<int> (k);
  for (int i = 0; i < k; i++) {
    cin >> adj[u][i];
  }
}

void report (int u) {
  cout << "! " << u << endl;
}

bool root (int u) {
  return adj[u].size() == 2;
}

bool leaf (int u) {
  return adj[u].size() == 1;
}

bool seen (int u) {
  return !adj[u].empty();
}

int unseen_nb (int u) {
  for (int v : adj[u]) {
    if (!seen(v)) return v;
  }
  return -1;
}

void solve () {
  int h;
  cin >> h;

  for (int i = 1; i < 1 << h; i++) {
    adj[i].clear();
  }

  deque<int> cur_chain;
  do {
    if (cur_chain.empty()) {
      cur_chain.push_back(1);
      ask(1);
      if (root(1)) {
        report(1);
        return;
      }
      cur_chain.push_back(adj[1][0]);
      ask(adj[1][0]);
      if (root(adj[1][0])) {
        report(adj[1][0]);
        return;
      }
    } else {
      int mid = (int) cur_chain.size() / 2 + 1;
      while ((int) cur_chain.size() > mid) {
        cur_chain.pop_back();
      }
    }

    while (!leaf(cur_chain.front())) {
      int u = unseen_nb(cur_chain.front());
      ask(u);
      if (root(u)) {
        report(u);
        return;
      }
      cur_chain.push_front(u);
    }

    while (!leaf(cur_chain.back())) {
      int u = unseen_nb(cur_chain.back());
      ask(u);
      if (root(u)) {
        report(u);
        return;
      }
      cur_chain.push_back(u);
    }
  } while ((int) cur_chain.size() < 7);

  int source = cur_chain[(int) cur_chain.size() / 2];
  int reqd = h - (int) cur_chain.size() / 2 - 1;
  queue<pair<int, int>> Q;
  Q.push({source, 0});
  while (Q.front().second < reqd) {
    pair<int, int> qtop = Q.front();
    Q.pop();

    int cur = qtop.first;
    int dist = qtop.second;
    if (!seen(cur)) {
      ask(cur);
    }

    for (int nxt : adj[cur]) {
      if (!seen(nxt)) {
        Q.push({nxt, dist + 1});
      }
    }
  }

  while (Q.size() >= 2) {
    int cur = Q.front().first;
    Q.pop();

    ask(cur);
    if (root(cur)) {
      report(cur);
      return;
    }
  }
  report(Q.front().first);
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}