#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ask (const vector<int> &s) {
  cout << "? ";
  for (int u : s) {
    cout << u;
  }
  cout << endl;

  int resp;
  cin >> resp;
  return resp;
}

void report (int L) {
  cout << "! " << L << endl;
  exit(0);
}

int ask_weight (int pos, int m) {
  vector<int> arr (m, 0);
  arr[pos] = 1;
  return ask(arr);
}

const int MAX_M = 505;

int main () {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> ord;
  for (int i = 0; i < m; i++) {
    int w = ask_weight(i, m);
    ord.push_back({w, i});
  }

  sort(ord.begin(), ord.end());

  int last = 0;
  vector<int> on (m, 0);
  for (auto e : ord) {
    int w = e.first;
    int id = e.second;

    on[id] = 1;
    int cur = ask(on);
    if (cur == last + w) {
      last += w;
    } else {
      on[id] = 0;
    }
  }

  report(last);
}