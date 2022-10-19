#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// source: cp-algorithms
const int INF = 2;

int gauss (vector<vector<int>> a, vector<int> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]%3) > abs (a[sel][col]%3))
				sel = i;
		if (!(a[sel][col]%3))
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				int c = a[i][col] * a[row][col] % 3;
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}

	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
    if (where[i] != -1) {
			ans[i] = a[where[i]][m] * a[where[i]][i] % 3;
    }
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j] % 3;
		if ((sum - a[i][m])%3)
			return 0;
	}

	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    map<pair<int, int>, int> vars;
    int id = 0;
    map<int, int> var_to_out;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (c == -1) {
        vars[{a, b}] = id;
        vars[{b, a}] = id;
        var_to_out[id] = i;
        id++;
      }
      adj[a][b] = c;
      adj[b][a] = c;
      ans[i] = c;
    }


    vector<vector<int>> a;
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        for (int k = j+1; k <= n; k++) {
          int u = adj[i][j];
          int v = adj[j][k];
          int w = adj[k][i];
          //cout << i <<  " " << j << " " << k << " " << u << " " << v << " " << w << endl;
          if (!(u && v && w)){
            continue;
          }
          int tot = 0;
          vector<int> row(id+1);
          if (u != -1) {
            tot += u;
          }
          else {
            row[vars[{i, j}]] = 1;
          }
          if (v != -1) {
            tot += v;
          }
          else {
            row[vars[{j, k}]] = 1;
          }
          if (w != -1) {
            tot += w;
          }
          else {
            row[vars[{k, i}]] = 1;
          }
          row[id] = (6-tot)%3;
          if (u != -1 && v != -1 && w != -1) {
            if (tot % 3 != 0) {
              bad = 1;
            }
          }
          a.push_back(row);
        }
      }
    }
    if (bad) {
      cout << "-1\n";
      continue;
    }
    if (!a.size()) {
      for (int i: ans) cout << (i == -1 ? 3 : i) << ' ';
      cout << '\n';
      continue;
    }

    vector<int> linear_ans(id);
    if (!gauss(a, linear_ans)) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < id; i++) {
      int val = linear_ans[i];
      val = (val%3+3)%3;
      if (val == 0) val = 3;
      ans[var_to_out[i]] = val;
    }

    for (int i: ans) cout << i << ' ';
    cout << '\n';
  }
}