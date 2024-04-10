#include <bits/stdc++.h>
using namespace std;

vector<int> matching;
vector<bool> used;

bool kuhn(int v, vector<vector<int>>& rowadj) {
  if (used[v]) return 0;
  used[v] = 1;
  for (int j: rowadj[v]) {
    if (matching[j] == -1 || kuhn(matching[j], rowadj)) {
      matching[j] = v;
      return 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool ops[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ops[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'B') {
        ops[i][j] = 1-ops[i][j];
        if (j > 0) ops[i][j-1] = 1-ops[i][j-1];
        if (i > 0) ops[i-1][j] = 1-ops[i-1][j];
        if (i > 0 && j > 0) ops[i-1][j-1] = 1-ops[i-1][j-1];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ops[i][j]) {
        ans++;
      }
    }
  }


  // find maximum matching
  vector<int> validrows;
  vector<int> validcols;
  for (int i = 0; i < n-1; i++) {
    if (ops[i][m-1]) validrows.push_back(i);
  }
  for (int j = 0; j < m-1; j++) {
    if (ops[n-1][j]) validcols.push_back(j);
  }

	int k = validrows.size();
	int l = validcols.size();
  vector<vector<int>> rowadj(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < l; j++) {
      if (ops[validrows[i]][validcols[j]]) {
        rowadj[i].push_back(j);
      }
    }
  }
  int matches = 0;
  matching.assign(l, -1);
  for (int i = 0; i < k; i++) {
    used.assign(k, 0);
    matches += kuhn(i, rowadj);
  }

  ans -= matches;
  if (matches & 1) {
    if (ops[n-1][m-1]) {
      ans--;
    }
    else {
      ans++;
    }
  }

  cout << ans << endl;
}