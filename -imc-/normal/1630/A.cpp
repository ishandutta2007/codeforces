#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void print(vector<pair<int, int>> ans, int k, bool p = false) {
  int ss = 0;
  for (auto it : ans) {
    if (p) {
      cout << it.first << " " << it.second << "\n";
    }
    ss += (it.first & it.second);
  }

  //cout.flush();

  //cout << "expected " << k << " got " << ss << endl;
  assert(ss == k);
}

vector<pair<int, int>> solve(int n, int k) {
  if (n == 4) {
    vector<pair<int, int>> ans;
    if (k == 0) {
      ans = {{0, 3}, {1, 2}};
    }
    if (k == 1) {
      ans ={{0, 2}, {1, 3}};
    }
    if (k == 2) {
      ans = {{0, 1}, {2, 3}};
    }
    print(ans, k);
    return ans;
  }

  if (n == 8 && k == 3) {
    vector<pair<int, int>> ans = {{3, 7}, {0, 5}, {1, 6}, {2, 4}};
    print(ans, k);
    return ans;
  }

  if (n == 8 && k == 7) {
    vector<pair<int, int>> ans = {{7,6}, {5, 3}, {2, 4}, {0, 1}};
    print(ans, k);
    return ans;
  }

  {
    int increments = k % 4;

    auto a = solve(n / 2, (k - increments) / 4);

    vector<pair<int, int>> res;
    int iter = 0;
    for (auto it : a) {
      if (increments == 0) {
        res.emplace_back(it.first * 2 + 0, it.second * 2 + 1);
        res.emplace_back(it.first * 2 + 1, it.second * 2 + 0);
      } else {
        res.emplace_back(it.first * 2 + 0, it.second * 2 + 0);
        res.emplace_back(it.first * 2 + 1, it.second * 2 + 1);
        --increments;
      }
    }
    print(res, k);
    assert(increments == 0);

    return res;
  }
}

void solve(bool read = true) {
  int n, k;
  cin >> n >> k;

  if ((n == 4 && k == 3)) {
    cout << "-1\n";
    return;
  }

  auto ans = solve(n, k);
  print(ans, k, true);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}