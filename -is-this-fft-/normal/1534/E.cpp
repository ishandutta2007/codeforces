#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 505;

int ask (const vector<int> &query) {
  cout << "? ";
  for (int u : query) {
    cout << u << " ";
  }
  cout << endl;

  int ans;
  cin >> ans;
  return ans;
}

vector<int> even, odd;

int K;
int make_step (int cur, int nxt) {
  int to_uncov = (cur + K - nxt) / 2;
  int to_cov = K - to_uncov;

  vector<int> query;
  
  vector<int> ote;
  for (int i = 0; i < to_uncov; i++) {
    ote.push_back(odd.back());
    query.push_back(odd.back());
    odd.pop_back();
  }

  vector<int> eto;
  for (int i = 0; i < to_cov; i++) {
    eto.push_back(even.back());
    query.push_back(even.back());
    even.pop_back();
  }

  int ans = ask(query);

  for (auto u : ote) {
    even.push_back(u);
  }

  for (auto u : eto) {
    odd.push_back(u);
  }

  return ans;
}

int dist [MAX_N], last [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> K;

  for (int i = 0; i <= n; i++) {
    dist[i] = MAX_N;
  }
  dist[0] = 0;

  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    int cov = cur, uncov = n - cur;
    for (int i = 0; i <= min(K, cov); i++) { // # of covered to uncover
      if (K - i > uncov) {
        continue;
      }

      int ncov = cov - i + K - i;
      if (dist[ncov] == MAX_N) {
        dist[ncov] = dist[cur] + 1;
        last[ncov] = cur;
        Q.push(ncov);
      }
    }
  }

  if (dist[n] == MAX_N) {
    cout << -1 << endl;
    exit(0);
  }

  vector<int> path;
  for (int cur = n; cur != 0; cur = last[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());

  for (int i = 1; i <= n; i++) {
    even.push_back(i);
  }
  
  int cur = 0, ans = 0;
  for (int nxt : path) {
    ans ^= make_step(cur, nxt);
    cur = nxt;
  }

  cout << "! " << ans << endl;
}