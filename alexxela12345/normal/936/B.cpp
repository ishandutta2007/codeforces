#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define endl '\n'
#endif

typedef long long ll;
typedef long double ldb;

template<typename T1, typename T2>
istream& operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

template<typename T>
istream& operator>>(istream& in, vector<T> &vec) {
  for (auto &el : vec) {
    in >> el;
  }
  return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> &vec) {
  for (auto &el : vec) {
    out << el << " ";
  }
  return out;
}

vector<vector<int>> g;
vector<vector<int>> used;
vector<int> st;
int canDraw = 0;

void dfs(int u, int p) {
  st.push_back(u);
  used[u][p] = 1;
  if (p == 1 && g[u].empty()) {
    cout << "Win" << endl;
    for (int el : st) {
      cout << el + 1 << " ";
    }
    cout << endl;
    exit(0);
  }
  for (int v : g[u]) {
    if (!used[v][1 - p]) {
      dfs(v, 1 - p);
    } else if (used[v][1 - p] == 1) {
      canDraw = 1;
    }
  }
  used[u][p] = 2;
  st.pop_back();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  used.resize(n, vector<int> (2));
  g.resize(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      x--;
      g[i].push_back(x);
    }
  }
  int s;
  cin >> s;
  dfs(s - 1, 0);
  if (canDraw) {
    cout << "Draw";
  } else {
    cout << "Lose";
  }
  cout << endl;
  return 0;
}