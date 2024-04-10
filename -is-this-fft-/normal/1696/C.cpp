#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<pair<int, ll>> normalize (const vector<int> &vec, int m) {
  vector<pair<int, ll>> ans;
  for (int u : vec) {
    int mul = 1;
    while (u % m == 0) {
      mul *= m;
      u /= m;
    }

    if (!ans.empty() && ans.back().first == u) {
      ans.back().second += mul;
    } else {
      ans.push_back({u, mul});
    }
  }

  return ans;
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int K;
  cin >> K;

  vector<int> b (K);
  for (int i = 0; i < K; i++) {
    cin >> b[i];
  }

  if (normalize(a, m) == normalize(b, m)) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
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