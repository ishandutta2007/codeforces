#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N], b[N];
int p[N], q[N];
vector<pair<int, int>> v[N];

bool check_ind(int i) {
  if (p[i] < a[i] || p[i] > b[i]) return 0;
  return 1;
}

bool check(int n) {
  for (int i = 1; i <= n; i++) {
    if (!check_ind(i)) return 0;
  }
  return 1;
}

void print(int n) {
  for (int i = 1; i <= n; i++) {
    cout << p[i] << " \n"[i==n];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    v[a[i]].emplace_back(-b[i], i);
  }

  vector<pair<int, int>> pairs_to_check;
  for (int i = 1; i <= n; i++) {
    for (pair<int, int>& e: v[i]) {
      pq.push(e);
    }
    q[i] = pq.top().second;
    p[q[i]] = i;
    pq.pop();
    if (!pq.empty()) {
      pairs_to_check.emplace_back(q[i], pq.top().second);
    }
  }

  for (pair<int, int>& e: pairs_to_check) {
    swap(p[e.first], p[e.second]);
    if (check_ind(e.first) && check_ind(e.second)) {
      cout << "NO\n";
      print(n);
      swap(p[e.first], p[e.second]);
      print(n);
      return 0;
    }
    swap(p[e.first], p[e.second]);
  }
  cout << "YES\n";
  print(n);
}