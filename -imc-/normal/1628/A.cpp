#include <bits/stdc++.h>

using namespace std;

using li = long long;

void solve(bool read = true) {
  int n;
  cin >> n;

  vector<vector<int>> cnt(n + 1);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x].push_back(i);
  }

  for (auto& it : cnt) {
    reverse(it.begin(), it.end());
  }

  vector<int> b;

  int last_l = 0;

  while (true) {
    int mex = 0;
    int l = 0;

    while (!cnt[mex].empty()) {
      l = max(l, cnt[mex].back() + 1);
      ++mex;
    }

    if (mex == 0) {
      break;
    }
    last_l = l;

    for (int i = 0; i < mex; ++i) {
      while (!cnt[i].empty() && cnt[i].back() < last_l) {
        cnt[i].pop_back();
      }
    }

    b.push_back(mex);
  }

  for (auto& it : cnt) {
    while (!it.empty() && it.back() < last_l) {
      it.pop_back();
    }
    for (size_t i = 0; i < it.size(); ++i) {
      b.push_back(0);
    }
  }

  cout << b.size() << "\n";
  for (auto it : b) {
    cout << it << " ";
  }
  cout << "\n";
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