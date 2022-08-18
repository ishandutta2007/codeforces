#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 5;
const int N = 720720;
const int VC = N + 1;

vector<int> out [VC];

int dist [VC];
void calc_dist (int src) {
  for (int i = 0; i < VC; i++) {
    dist[i] = INF;
  }

  queue<int> Q;
  dist[src] = 0;
  Q.push(src);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    
    for (int nxt : out[cur]) {
      if (dist[nxt] == INF) {
        dist[nxt] = dist[cur] + 1;
        Q.push(nxt);
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b;
  int K;
  cin >> a >> b >> K;

  for (int i = 1; i < VC; i++) {
    out[i].push_back(i - 1);
    for (int j = 2; j <= K; j++) {
      out[i].push_back(i - i % j);
    }
  }

  if (a / N == b / N) {
    a %= N;
    b %= N;
    calc_dist(a);
    cout << dist[b] << '\n';
    return 0;
  }

  calc_dist(a % N);
  int atoz = dist[0];

  calc_dist(N);
  int ztoz = dist[0];
  int ztob = dist[b % N];

  ll diff = a / N - b / N;
  ll ans = (ll) atoz + (diff - 1) * (ll) ztoz + (ll) ztob;
  cout << ans << endl;
}