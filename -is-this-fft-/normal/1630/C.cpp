#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> Interval;
#define l first
#define r second

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int L [MAX_N];
int R [MAX_N];
int prv [MAX_N];
int dp [MAX_N];

int time_at (int p) {
  if (p < 0) {
    return L[-p];
  } else {
    return R[p];
  }
}

bool by_ev_time (int p, int q) {
  return time_at(p) < time_at(q);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    L[i] = MAX_N;
  }
  
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    L[arr[i]] = min(L[arr[i]], i);
    R[arr[i]] = i;
  }

  vector<int> evs;
  for (int i = 1; i <= n; i++) {
    if (L[i] < R[i]) {
      evs.push_back(-i);
      evs.push_back(i);
    }
  }

  vector<int> good;
  sort(evs.begin(), evs.end(), by_ev_time);
  set<pair<int, int>> rends; // <R[i], i>
  for (auto e : evs) {
    int idx = abs(e);
    if (e < 0) {
      // open
      if (rends.empty() || R[idx] > rends.rbegin()->first) {
        good.push_back(idx);
        rends.insert(make_pair(R[idx], idx));

        if (rends.empty()) {
          prv[idx] = idx;
        } else {
          prv[idx] = rends.begin()->second;
        }
      }
    } else {
      // close
      rends.erase(make_pair(R[idx], idx));
    }
  }

  int ans = 0;
  int curl = 0, curr = 0, ldp = 0;
  for (int u : good) {
    if (prv[u] == u) {
      // start of the new segment
      ans += curr - curl;
      ans -= ldp;

      curl = L[u] + 1;
      curr = R[u];
      dp[u] = 0;
    } else {
      curr = R[u];
      dp[u] = 1 + dp[prv[u]];
    }

    ldp = dp[u];
  }

  ans += curr - curl;
  ans -= ldp;

  cout << ans << '\n';
}