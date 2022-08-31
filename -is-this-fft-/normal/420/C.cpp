#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 3e5 + 5;

int cnt [MAX_N];
map<pair<int, int>, int> cnt_pr;

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    cnt[u]++;
    cnt[v]++;
    if (u > v) swap(u, v);
    cnt_pr[{u, v}]++;
  }

  vector<int> cnts;
  for (int i = 1; i <= n; i++) {
    cnts.push_back(cnt[i]);
  }
  sort(cnts.begin(), cnts.end(), greater<int>());

  ll ans = 0;
  int rptr = n - 1;
  for (int i = 0; i < n - 1; i++) {
    while (i < rptr && cnts[i] + cnts[rptr] < K) {
      rptr--;
    }

    if (i >= rptr) {
      break;
    }

    ans += rptr - i;
  }
  
  for (auto it = cnt_pr.begin(); it != cnt_pr.end(); it++) {
    int u = it->first.first;
    int v = it->first.second;
    int c = it->second;

    if (cnt[u] + cnt[v] >= K && cnt[u] + cnt[v] - c < K) {
      ans--;
    }
  }

  cout << ans << endl;
}