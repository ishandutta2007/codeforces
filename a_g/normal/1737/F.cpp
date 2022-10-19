#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int>& b) {
  if (*max_element(b.begin(), b.end()) >= 4) {
    // forces neighboring multiples of p^2
    return {};
  }
  int c3 = count(b.begin(), b.end(), 3);
  int c2 = count(b.begin(), b.end(), 2);
  int c1 = count(b.begin(), b.end(), 1);
  if (c3 >= 2) {
    // forces neighboring multiples of pq
    return {};
  }
  if (c3 >= 1 && c2 >= 1) {
    // brute force checked (for c3 = 1, c2 = 1, c1 = 0)
    return {};
  }
  if (c3 == 1) {
    vector<vector<int>> ans = {{2}, {1}, {3}};
    int n = 1;
    while (c1--) {
      n++;
      for (int i = 0; i < (int)ans.size(); i++) {
        ans[i].push_back(i&1);
      }
      vector<vector<int>> newans = ans;
      vector<int> e(n), o(n);
      e[n-1] = 1;
      o[0] = 1;
      newans.push_back(e);
      for (vector<int>& v: ans) {
        v.back() = 1-v.back();
      }
      newans.insert(newans.end(), ans.begin(), ans.end());
      int p = find(newans.begin(), newans.end(), e)-newans.begin();
      int q = find(newans.begin(), newans.end(), o)-newans.begin();
      swap(newans[p], newans[q]);
      swap(ans, newans);
    }
    for (vector<int>& v: ans) {
      reverse(v.begin(), v.end());
    }
    return ans;
  }
  /*
  if (c3 >= 1 && c1 >= 3) {
    // not sure
    return {};
  }
  if (c3 == 1 && c1 == 2) {
    return
    {
      {1,1,3},
        {1,0,0},
        {1,0,2},
        {1,1,0},
        {0,1,2},
        {0,1,0},
        {1,1,2},
        {0,0,1},
        {1,0,3},
        {0,1,1},
        {0,0,2},
        {1,1,1},
        {0,0,3},
        {1,0,1},
        {0,1,3},
    };
  }
  if (c3 == 1 && c1 == 1) {
    return {
      {0, 2},
        {1, 1},
        {0, 3},
        {0, 1},
        {1, 2},
        {1, 0},
        {1, 3}
    };
  }
  if (c3 == 1) {
    assert(c2 == 0 && c1 == 0);
    return {{2}, {1}, {3}};
  }
  */
  if (c2 >= 3) {
    // brute forced (c2 = 3, c1 = 0)
    return {};
  }

  vector<vector<int>> ans;
  if (c2 == 2) {
    ans = {
      {2, 2},
      {1, 0},
      {2, 1},
      {0, 2},
      {1, 1},
      {2, 0},
      {1, 2},
      {0, 1}
    };
  }
  if (c2 == 1) {
    ans = {{2}, {1}};
  }

  while (c1--) {
    vector<vector<int>> newans = ans;
    reverse(ans.begin(), ans.end());
    newans.insert(newans.end(), ans.begin(), ans.end());
    for (int i = 0; i < (int)newans.size(); i++) {
      newans[i].push_back(i&1);
    }
    int n = (newans.size() ? (int)newans[0].size() : 1);
    vector<int> e(n);
    e[n-1] = 1;
    newans.push_back(e);
    swap(ans, newans);
  }
  for (vector<int>& v: ans) {
    reverse(v.begin(), v.end());
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    vector<pair<int, int>> bp(m);
    for (int i = 0; i < m; i++) {
      bp[i].second = i;
      cin >> bp[i].first;
    }
    vector<int> b(m);
    sort(bp.begin(), bp.end());
    for (int i = 0; i < m; i++) {
      b[i] = bp[i].first;
    }
    vector<vector<int>> ansp = solve(b);
    if (ansp.empty()) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int>> ans = ansp;
    for (int i = 0; i < (int)ans.size(); i++) {
      for (int j = 0; j < m; j++) {
        ans[i][bp[j].second] = ansp[i][j];
      }
      for (int x: ans[i]) {
        cout << x << ' ';
      }
      cout << '\n';
    }

    /*
    int prod = 1;
    for (int x: b) {
      prod = (x+1)*prod;
    }
    assert((int)ans.size() == prod-1);
    for (int i = 0; i < (int)ans.size()-1; i++) {
      int c = 0;
      for (int j = 0; j < m; j++) {
        int k = min(ans[i][j], ans[i+1][j]);
        assert(k <= 1);
        if (k == 1) c++;
      }
      assert(c == 1);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size()-1; i++) {
      assert(ans[i] != ans[i+1]);
    }
    */

    /*
    assert(b.size() == 3);
    vector<vector<int>> a;
    for (int i = 0; i <= b[0]; i++) {
      for (int j = 0; j <= b[1]; j++) {
        for (int k = 0; k <= b[2]; k++) {
        if (i+j+k == 0) continue;
        a.push_back({i, j, k});
        }
      }
    }
    sort(a.begin(), a.end());
    do {
      bool ok = 1;
      for (int i = 0; i < (int)a.size()-1; i++) {
        int c = 0;
        for (int j = 0; j < 3; j++) {
          int k = min(a[i][j], a[i+1][j]);
          if (k > 1) {
            ok = 0;
            break;
          }
          if (k == 1) c++;
        }
        if (c != 1) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        for (vector<int>& cell: a) {
          for (int x: cell) {
            cout << x << ' ';
          }
          cout << '\n';
        }
        return 0;
      }
    } while (next_permutation(a.begin(), a.end()));
    */
  }
}