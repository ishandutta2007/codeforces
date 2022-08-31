#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void solve () {
  int n, l;
  cin >> n >> l;

  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  arr[n + 1] = l;

  vector<int> speed = {1, -1};
  vector<int> pos = {0, n + 1};
  vector<double> last = {0, 0};
  vector<int> dir = {1, -1};

  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> PQ;
  PQ.push(make_pair(arr[1], 0));
  PQ.push(make_pair(l - arr[n], 1));

  while (!PQ.empty()) {
    auto pr = PQ.top();
    PQ.pop();

    double t = pr.first;
    int idx = pr.second;

    speed[idx] += dir[idx];
    pos[idx] += dir[idx];
    last[idx] = t;


    if (pos[0] + 1 == pos[1]) {
      // endgame
      vector<double> rpos (2);
      for (int i = 0; i < 2; i++) {
        rpos[i] = arr[pos[i]] + (t - last[i]) * (double) speed[i];
      }

      double add = (rpos[1] - rpos[0]) / (double) (speed[0] - speed[1]);
      cout << fixed << setprecision(12) << t + add << '\n';
      return;
    } else {
      double time_to_nxt = (double) (arr[pos[idx] + dir[idx]] - arr[pos[idx]]) / (double) speed[idx];
      PQ.push(make_pair(t + time_to_nxt, idx));
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
 
  for (int i = 0; i < testc; i++) {
    solve();
  }
}