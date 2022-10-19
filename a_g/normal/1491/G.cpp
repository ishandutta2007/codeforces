#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, a[N];
vector<pair<int, int>> ops;
bool vis[N];

void debug() {
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void operate(int i, int j) {
  ops.emplace_back(i, j);
  swap(a[i], a[j]);
  a[i] = -a[i];
  a[j] = -a[j];
}

void fix_cycles(vector<int>& c1, vector<int>& c2) {
  int p = c1.size();
  int q = c2.size();
  operate(c1[p-1], c2[q-1]);
  for (int i = 0; i < q-1; i++) {
    operate(c1[p-1], c2[i]);
  }
  for (int i = 0; i < p-1; i++) {
    operate(c2[q-1], c1[i]);
  }
  operate(c1[p-1], c2[q-1]);
}

void fix_solo(vector<int>& c) {
  int p = c.size();
  if (p == 2) {
    for (int i = 1; i <= n; i++) {
      if (a[i] == i) {
        operate(c[0], i);
        operate(c[1], i);
        operate(c[0], i);
        return;
      }
    }
  }
  assert(p>2);
  for (int i = 2; i < p; i++) {
    operate(c[0], c[i]);
  }
  operate(c[0], c[1]);
  operate(c[1], c[2]);
  operate(c[0], c[2]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> cycles;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cycles.emplace_back(1, i);
    vis[i] = 1;
    while (!vis[a[cycles.back().back()]]) {
      cycles.back().emplace_back(a[cycles.back().back()]);
      vis[cycles.back().back()] = 1;
    }
  }
  sort(cycles.begin(), cycles.end(), [&] (vector<int>& a, vector<int>& b) {
      return a.size() > b.size();
      });
  for (int i = 0; i < cycles.size(); i += 2) {
    if (cycles[i].size() == 1) break;
    if (i == (int)cycles.size()-1 || cycles[i+1].size() == 1) {
      fix_solo(cycles[i]);
    }
    else {
      fix_cycles(cycles[i], cycles[i+1]);
    }
  }

  assert(ops.size() <= n+1);
  for (int i = 1; i <= n; i++) {
    assert(a[i] == i);
  }
  cout << ops.size() << '\n';
  for (pair<int, int>& op: ops) {
    cout << op.first << " " << op.second << '\n';
  }
}