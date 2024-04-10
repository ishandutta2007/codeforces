#include <iostream>
#include <set>

using namespace std;

void failure () {
  cerr << " ERROR " << endl;
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 505;

const int dx [4] = {0, 1, 0, -1};
const int dy [4] = {1, 0, -1, 0};

int grid [MAX_N][MAX_N];
int arr [MAX_N];

struct Comp {
  bool operator() (pair<int, int> p, pair<int, int> q) const {
    if (p.second != q.second) {
      return p.second < q.second;
    }
    return p.first < q.first;
  }
};

void add (pair<int, int> pt, int val, set<pair<int, int>, Comp> &nbors) {
  grid[pt.first][pt.second] = val;
  for (int k = 0; k < 4; k++) {
    auto nxt = make_pair(pt.first + dx[k], pt.second + dy[k]);
    if (grid[nxt.first][nxt.second] == 0) {
      nbors.insert(nxt);
    }
  }
}


int main () {
  int n;
  cin >> n;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      grid[i][j] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      grid[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    auto u = arr[i];
    set<pair<int, int>, Comp> cur;
    cur.insert(make_pair(i, i));
    for (int j = 0; j < u; j++) {
      if (cur.empty()) {
	failure();
      }

      auto pr = *cur.begin();
      cur.erase(pr);
      add(pr, u, cur);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << grid[i][j] << " ";
    }
    cout << '\n';
  }
}