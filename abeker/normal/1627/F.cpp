#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXK = 5e2 + 5;
const int INF = 1e9;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template <class T>
class MyArray {
  vector <vector <T>> arr;
public:
  MyArray(int n, T val) {
    arr.resize(n, vector <T> (n, val));
  }
  MyArray() {}
  T& operator [](pii cell) {
    return arr[cell.first][cell.second];
  }
  vector <T>& operator [](int row) {
    return arr[row];
  }
};

int N, K;
MyArray <array <int, 4>> weight;
MyArray <int> dist;

void flip(int &x, int &y) {
  x = K + 1 - x;
  y = K + 1 - y;
}

void add_edge(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    int y = min(y1, y2);
    weight[x1][y][0]++;
    weight[x1 - 1][y][2]++;
  }
  else {
    int x = min(x1, x2);
    weight[x][y1 - 1][1]++;
    weight[x][y1][3]++;
  }
}

void load() {
  scanf("%d%d", &N, &K);
  weight = MyArray(K + 1, array <int, 4> ());
  dist = MyArray(K + 1, INF);
  for (int i = 0; i < N; i++) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    for (int j = 0; j < 2; j++) {
      add_edge(r1, c1, r2, c2);
      flip(r1, c1);
      flip(r2, c2);
    }
  }
}

bool in_range(pii pos, int lo, int hi) {
  return pos.first >= lo && pos.first <= hi && pos.second >= lo && pos.second <= hi;
}

int solve() {
  auto cmp = [&](pii lhs, pii rhs) {
    if (dist[lhs] != dist[rhs])
      return dist[lhs] < dist[rhs];
    return lhs < rhs;
  };
  set <pii, decltype(cmp)> curr(cmp);
  dist[K / 2][K / 2] = 0;
  for (int i = 0; i <= K; i++)
    for (int j = 0; j <= K; j++)
      curr.insert({i, j});
  int sol = INF;
  while (!curr.empty()) {
    pii tmp = *curr.begin();
    curr.erase(tmp);
    if (!in_range(tmp, 1, K - 1))
      sol = min(sol, dist[tmp]);
    for (int i = 0; i < 4; i++) {
      pii nxt = {tmp.first + dx[i], tmp.second + dy[i]};
      int cost = dist[tmp] + weight[tmp][i];
      if (in_range(nxt, 0, K) && cost < dist[nxt]) {
        curr.erase(nxt);
        dist[nxt] = cost;
        curr.insert(nxt);
      }
    }
  }
  return N - sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}