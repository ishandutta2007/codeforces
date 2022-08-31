#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

int n;

vector<int> ask (int u) {
  cout << "? " << u + 1 << endl;

  vector<int> resp (n);
  for (int i = 0; i < n; i++) {
    cin >> resp[i];
  }
  return resp;
}

void report (const vector<pair<int, int>> &edges) {
  cout << "!" << endl;
  for (auto e : edges) {
    cout << e.first + 1 << " " << e.second + 1 << endl;
  }
  exit(0);
}

void proc (int u, const vector<int> &dists, vector<pair<int, int>> &edges) {
  for (int i = 0; i < n; i++) {
    if (dists[i] == 1) {
      edges.push_back(make_pair(u, i));
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  auto d0 = ask(0);
  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
    if (d0[i] % 2 == 0) {
      even.push_back(i);
    } else {
      odd.push_back(i);
    }
  }

  vector<pair<int, int>> ans;
  if ((int) even.size() <= (int) odd.size()) {
    proc(0, d0, ans);
  } else {
    swap(even, odd);
  }

  for (auto u : even) {
    if (u != 0) {
      auto du = ask(u);
      proc(u, du, ans);
    }
  }

  report(ans);
}