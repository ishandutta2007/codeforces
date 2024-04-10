#include <iostream>
#include <set>

using namespace std;

const int INF = 1e9 + 200;
const int MAX_N = 205;

int arr [MAX_N];
set<pair<int, int>> inside;
set<pair<int, int>> outside;

int best_diff (int K) {
  K = min(K, (int) inside.size());
  K = min(K, (int) outside.size());

  auto ins = inside.begin();
  auto outs = outside.rbegin();

  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += max(0, outs->first - ins->first);
    
    ins = next(ins);
    outs = next(outs);
  }
  return ans;
}

int main () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = -INF;
  for (int l = 0; l < n; l++) {
    inside.clear();
    outside.clear();

    for (int i = 0; i < n; i++) {
      outside.insert(make_pair(arr[i], i));
    }

    int cur = 0;
    for (int r = l; r < n; r++) {
      outside.erase(make_pair(arr[r], r));
      inside.insert(make_pair(arr[r], r));
      cur += arr[r];

      ans = max(ans, cur + best_diff(K));
    }
  }

  cout << ans << endl;
}