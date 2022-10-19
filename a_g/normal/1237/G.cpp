#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int LOG = 17;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  int avg = accumulate(a.begin(), a.end(), 0)/n;

  map<int, vector<int>> cut_to_indices;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cut_to_indices[cur].push_back(i);
    cur += a[i]-avg;
  }

  tuple<int, int, int> best_state = make_tuple(0, 0, 0);
  vector<int> closest_index(k-1, INF);
  for (auto& [cut, indices]: cut_to_indices) {
    int m = (int)indices.size();
    for (int i = m-1; i >= 0; i--) {
      closest_index[(indices[i]+n)%(k-1)] = i+m;
    }
    vector<vector<int>> jmp(m, vector<int>(LOG, INF));
    for (int i = m-1; i >= 0; i--) {
      jmp[i][0] = closest_index[(indices[i]+1)%(k-1)];
      closest_index[indices[i]%(k-1)] = i;
    }
    for (int l = 1; l < LOG; l++) {
      for (int i = 0; i < m; i++) {
        int v = jmp[i][l-1];
        if (v > i+m) jmp[i][l] = INF;
        else if (v < m) jmp[i][l] = jmp[v][l-1];
        else jmp[i][l] = jmp[v-m][l-1]+m;
      }
    }
    for (int i = 0; i < m; i++) {
      int v = i;
      int len = 0;
      for (int j = LOG-1; j >= 0; j--) {
        int u = (v >= m ? jmp[v-m][j]+m : jmp[v][j]);
        if (u < i+m) {
          v = u;
          len += 1<<j;
        }
      }
      best_state = max(best_state, make_tuple(len, cut, i));
    }

    for (int x: indices) {
      closest_index[x%(k-1)] = INF;
      closest_index[(x+n)%(k-1)] = INF;
    }
  }

  int len, cut, z;
  tie(len, cut, z) = best_state;
  cout << (n+k-3-len)/(k-1) << '\n';
  int m = (int)cut_to_indices[cut].size();
  vector<int> cuts(1, cut_to_indices[cut][z]);
  for (int j = z+1; j < m; j++) {
    if ((cut_to_indices[cut][j]-cuts.back()-1)%(k-1) == 0) {
      cuts.push_back(cut_to_indices[cut][j]);
    }
  }
  for (int j = 0; j < z; j++) {
    if ((cut_to_indices[cut][j]+n-cuts.back()-1)%(k-1) == 0) {
      cuts.push_back(cut_to_indices[cut][j]+n);
    }
  }
  cuts.push_back(cut_to_indices[cut][z]+n);

  vector<pair<int, vector<int>>> ans;
  vector<int> v(k);
  function<void(int, int, int)> solve = [&] (int l, int r, int leftval) {
    int sum = 0;
    if (r-l <= k) {
      for (int i = l; i < r; i++) sum += a[i%n];
      assert(sum == (r-l)*avg+(leftval-avg));
      if (r-l == 1) return;
      for (int i = l; i < l+k; i++) {
        int target;
        if (i == l) target = leftval;
        else if (i < r) target = avg;
        else target = a[i%n];
        v[i-l] = target;
        a[i%n] = target;
      }
      ans.push_back(make_pair(l%n, v));
      return;
    }
    for (int i = l; i < l+k; i++) sum += a[i%n];
    int diff = sum-(k-1)*avg-leftval;
    if (diff >= 0) {
      for (int i = l; i < l+k; i++) {
        int target;
        if (i == l) target = leftval;
        else if (i == l+k-1) target = avg+diff;
        else target = avg;
        v[i-l] = target;
        a[i%n] = target;
      }
      ans.push_back(make_pair(l%n, v));
      solve(l+k-1, r, avg);
      return;
    }
    solve(l+k-1, r, a[(l+k-1)%n]-diff);
    for (int i = l; i < l+k; i++) {
      int target;
      if (i == l) target = leftval;
      else target = avg;
      v[i-l] = target;
      a[i%n] = target;
    }
    ans.push_back(make_pair(l%n, v));
  };
  for (int i = 0; i < (int)cuts.size()-1; i++) {
    solve(cuts[i], cuts[i+1], avg);
  }

  for (auto& [i, nums]: ans) {
    cout << i;
    for (int x: nums) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
}