#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int c[N][N];
vector<vector<int>> ops;

void work(vector<int>& op) {
  ops.push_back(op);
  for (int i = 0; i < n; i++) {
    c[i][op[i]]--;
    c[(i+1)%n][op[i]]++;
  }
}

void phase1 () {
  /* Everyone gets one of each card */
  vector<int> dup(n, -1);
  bool done = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] > 1) {
        dup[i] = j;
        done = 0;
        break;
      }
    }
  }

  if (done) return;
  for (int i = 0; i < n; i++) {
    if (dup[i] != -1) {
      for (int j = (i+1)%n; dup[j] == -1; j = (j+1)%n) {
        dup[j] = dup[i];
      }
    }
  }
  work(dup);
  phase1();
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      c[i][k-1]++;
    }
  }
  phase1();
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int start = (i+n-j)%n;
      vector<int> op(n);
      for (int k = 0; k < n; k++) {
        op[k] = (start+k)%n;
      }
      work(op);
    }
  }

  cout << ops.size() << '\n';
  for (vector<int>& op: ops) {
    for (int k: op) {
      cout << k+1 << ' ';
    }
    cout << '\n';
  }
}