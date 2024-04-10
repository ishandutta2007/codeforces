#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

#define endl '\n'

struct Stack {
  vector<pair<int, int>> arr;

  Stack() {
    arr.push_back({-1e18, -1e18});
  }

  void push(int x) {
    arr.emplace_back(x, max(x, arr.back().second));
  }

  void pop() {
    arr.pop_back();
  }

  int top() {
    return arr.back().first;
  }

  int getMax() {
    return arr.back().second;
  }
  
  bool empty() {
    return arr.size() == 1;
  }
};

struct Queue {
  Stack head, tail;

  Queue() {}

  void push(int x) {
    tail.push(x);
  }

  void pop() {
    if (head.empty()) {
      while (!tail.empty()) {
        head.push(tail.top());
        tail.pop();
      }
    }
    head.pop();
  }

  int getMax() {
    return max(head.getMax(), tail.getMax());
  }
};

void solve() {
  int n, m;
  int d;
  cin >> n >> m >> d;
  vector<int> a(m), b(m), t(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> t[i];
    a[i]--;
  }
  // dp[i][j] - i first fireworks position j
  vector<vector<int>> dp(2, vector<int> (n));
  for (int i = 0; i < n; i++) {
    dp[1][i] = b[0] - abs(a[0] - i);
  }
  for (int i = 1; i < m; i++) {
    swap(dp[0], dp[1]);
    int l = 0;
    int r = 0;
    int dt = t[i] - t[i - 1];
    Queue q;
    for (int j = 0; j < n; j++) {
      while (r <= j + dt * d && r < n) {
        q.push(dp[0][r++]); 
      }
      while (l < j - dt * d) {
        q.pop();
        l++;
      }
      dp[1][j] = q.getMax() + b[i] - abs(a[i] - j);
    }
  }
  int best = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    best = max(best, dp[1][i]);
  }
  cout << best << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}