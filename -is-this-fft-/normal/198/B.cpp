#include <iostream>
#include <queue>

using namespace std;

void success () {
  cout << "YES" << endl;
  exit(0);
}

const int MAX_N = 2e5 + 5;
const int INF = 1e9 + 5;

bool blocked [MAX_N];
int dist [MAX_N];

int jmp (int pos, int K) {
  int bit = pos & 1;
  pos /= 2;
  pos += K;
  pos *= 2;
  pos += !bit;
  return pos;
}

int main () {
  int n, K;
  cin >> n >> K;

  string l, r;
  cin >> l >> r;

  n *= 2;
  for (int i = 0; i < n; i += 2) {
    blocked[i] = l[i / 2] == 'X';
  }
  for (int i = 1; i < n; i += 2) {
    blocked[i] = r[i / 2] == 'X';
  }

  for (int i = 0; i < n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;

  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    vector<int> adj = {cur - 2, cur + 2, jmp(cur, K)};
    for (int nxt : adj) {
      if (nxt < 0) {
        continue;
      }

      if (nxt >= n) {
        success();
      }

      if (blocked[nxt]) {
        continue;
      }

      if (dist[cur] + 1 > nxt / 2) {
        continue;
      }

      if (dist[nxt] != INF) {
        continue;
      }

      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }

  cout << "NO" << endl;
}