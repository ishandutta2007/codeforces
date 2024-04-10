#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

ll dist (ll x, ll y) {
  return sq(x - y);
}

void solve () {
  int n;
  cin >> n;

  vector<int> perm (n);
  int mid = n / 2;

  perm[0] = mid;
  for (int i = 1; i < mid; i++) {
    perm[i] = i - 1;
  }
  for (int i = mid; i < n - 1; i++) {
    perm[i] = i + 1;
  }
  perm[n - 1] = mid - 1;

  ll secc = 0;
  vector<pair<int, int>> ops;

  for (int i = mid - 1; i > 0; i--) {
    ops.push_back(make_pair(i, n - 1));
    secc += dist(i, n - 1);
  }

  for (int i = mid; i < n - 1; i++) {
    ops.push_back(make_pair(i, 0));
    secc += dist(0, i);
  }
  
  ops.push_back(make_pair(0, n - 1));
  secc += dist(0, n - 1);
  
  cout << secc << '\n';
  
  for (int u : perm) {
    cout << u + 1 << " ";
  }
  cout << '\n';

  cout << ops.size() << '\n';
  for (auto pr : ops) {
    cout << pr.first + 1 << " " << pr.second + 1 << '\n';
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