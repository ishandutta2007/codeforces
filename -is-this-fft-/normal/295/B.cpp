#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 505;

int dist [MAX_N][MAX_N];
int alive [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dist[i][j];
    }
  }

  vector<int> add_ord (n);
  for (int i = 0; i < n; i++) {
    cin >> add_ord[i];
  }
  reverse(add_ord.begin(), add_ord.end());

  vector<ll> ans;
  for (int k : add_ord) {
    ll cur = 0;
    alive[k] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        if (alive[i] && alive[j]) {
          cur += dist[i][j];
        }
      }
    }
    ans.push_back(cur);
  }

  reverse(ans.begin(), ans.end());

  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
}