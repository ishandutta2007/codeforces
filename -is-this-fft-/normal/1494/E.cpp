#include <iostream>
#include <map>

using namespace std;

int bidir_cnt;
int strong_cnt;
map<pair<int, int>, pair<char, char>> vals;

void upd (int u, int v, int add) {
  auto pr = vals[{u, v}];
  if (pr.first != 0 && pr.second != 0) {
    bidir_cnt += add;
    if (pr.first == pr.second) {
      strong_cnt += add;
    }
  }
}

void add (int u, int v, char c) {
  upd(min(u, v), max(u, v), -1);
             
  if (u < v) {
    vals[{u, v}].first = c;
  } else {
    vals[{v, u}].second = c;
  }

  upd(min(u, v), max(u, v), 1);
}

void del (int u, int v) {
  add(u, v, 0);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < qc; i++) {
    char type;
    cin >> type;

    if (type == '+') {
      int u, v;
      char c;
      cin >> u >> v >> c;

      add(u, v, c);
    } else if (type == '-') {
      int u, v;
      cin >> u >> v;

      del(u, v);
    } else {
      int k;
      cin >> k;

      if (k % 2 == 0) {
        cout << (strong_cnt != 0 ? "YES" : "NO") << '\n';
      } else {
        cout << (bidir_cnt != 0 ? "YES" : "NO") << '\n';
      }
    }
  }
}