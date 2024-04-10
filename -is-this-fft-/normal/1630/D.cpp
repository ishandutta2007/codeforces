#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;
const ll INF = 1e18 + 2000;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

pair<ll, ll> solve (vector<int> arr) {
  sort(arr.begin(), arr.end());

  int n = arr.size();
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  ll mx_ev = sum, mx_od = -INF;
  for (int i = 0; i < n; i++) {
    sum -= 2 * arr[i];
    if (i % 2 == 0) {
      mx_od = max(mx_od, sum);
    } else {
      mx_ev = max(mx_ev, sum);
    }
  }

  return make_pair(mx_ev, mx_od);
}

int arr [MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int gc = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    gc = gcd(gc, x);
  }

  vector<vector<int>> arrs (gc, vector<int> (0));
  for (int i = 0; i < n; i++) {
    arrs[i % gc].push_back(arr[i]);
  }

  ll even = 0, odd = 0;
  for (int i = 0; i < gc; i++) {
    auto pr = solve(arrs[i]);
    even += pr.first;
    odd += pr.second;
  }

  cout << max(even, odd) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}