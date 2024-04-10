#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e2 + 10;

int a[N][N];

void inv(int i, int j) {
  a[i][j] = 1 - a[i][j];
}

vector<vector<int>> answer;

void f3(int n, int m) {
  answer.push_back({});
  for (int i = n - 2; i <= n - 1; ++i) {
    for (int j = m - 2; j <= m - 1; ++j) {
      if (a[i][j]) {
        answer.back().push_back(i);
        answer.back().push_back(j);
        inv(i, j);
      }
    }
  }
}

void step(int x1, int y1, int x2, int y2, int x3, int y3) {
  answer.push_back({x1, y1, x2, y2, x3, y3});
  inv(x1, y1);
  inv(x2, y2);
  inv(x3, y3);
}

void f2(int n, int m) {
  int x = a[n - 2][m - 2];
  int b = a[n - 2][m - 1];
  int c = a[n - 1][m - 2];
  int d = a[n - 1][m - 1];
  if (b + x + c == 1) {
    step(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
    f3(n, m); 
    return;
  }
  if (x + c + d == 1) {
    step(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
    f3(n, m);
    return;
  }
  if (c + d + b == 1) {
    step(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
    f3(n, m);
    return;
  }
  assert(false);
}

void f1(int n, int m) {
  int x = a[n - 2][m - 2];
  int b = a[n - 2][m - 1];
  int c = a[n - 1][m - 2];
  int d = a[n - 1][m - 1];
  if (b + x + c == 1) {
    step(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
    f2(n, m); 
    return;
  }
  if (x + c + d == 1) {
    step(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
    f2(n, m);
    return;
  }
  if (c + d + b == 1) {
    step(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
    f2(n, m);
    return;
  }
  assert(false);
}

void f4(int n, int m) {
  step(n - 1, m - 1, n - 2, m - 1, n - 1, m - 2);
  f1(n, m);
}

void solve() {
  answer.clear();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      a[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (a[i][j]) {
        if (a[i][j + 1]) {
          step(i, j, i + 1, j, i, j + 1);
        } else {
          step(i, j, i + 1, j, i + 1, j + 1);
        }
      } else if (a[i][j + 1]) {
        step(i, j + 1, i + 1, j, i + 1, j + 1); 
      }
    }
  }

  for (int j = 0; j < m - 2; ++j) {
    if (!a[n - 2][j] && !a[n - 1][j]) {
      continue; 
    } else if (!a[n - 2][j] && a[n - 1][j]) {
      step(n - 1, j, n - 2, j + 1, n - 1, j + 1);
    } else if (a[n - 2][j] && !a[n - 1][j]) {
      step(n - 2, j, n - 2, j + 1, n - 1, j + 1);
    } else {
      step(n - 1, j, n - 2, j, n - 1, j + 1);
    }
  }

  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << a[i][j];
    cout << endl;
  }
  */

  int cnt = a[n - 1][m - 1] + a[n - 2][m - 1] + a[n - 1][m - 2] + a[n - 2][m - 2];
  if (cnt == 4) {
    f4(n, m);
  } else if (cnt == 3) {
    f3(n, m);
  } else if (cnt == 2) {
    f2(n, m);
  } else if (cnt == 1) {
    f1(n, m);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      assert(!a[i][j]);
    }
  }

  cout << answer.size() << "\n";
  for (auto v: answer) {
    for (auto x: v) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}