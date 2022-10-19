#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 400;
const int T = 200;
const int N = 35;
const int K = 8;
const int B = 10;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int fool;

struct Field {
  int a[M][M];
  
  Field() {
    for (int i = 0; i < M; ++i)
      fill(a[i], a[i] + M, 0);
  }

  int* operator[](int x) {
    return a[T + x] + T;
  }

  int& get(int x, int y) {
    x += T;
    y += T;

    if (x < 0 || x >= M 
        || y < 0 || y >= M)
      return fool;

    return a[x][y];
  }

  void print() {
    for (int i = -B; i < B; ++i, cerr << endl)
      for (int j = -B; j < B; ++j) {
        cerr << (get(i, j) ? "#" : ".");
      }
  }

} A[N][K];

void apply(Field &A, Field B, int x, int y) {
  for (int i = -T; i < T; ++i)
    for (int j = -T; j < T; ++j)
      A.get(i + x, j + y) |= B.get(i, j);
}

int n;
int t[N];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  reverse(t, t + n);
}

void kill() {
  //for (int d = 0; d < K; ++d)
    //A[0][d].get(0, 0) = 1;

  for (int i = 1; i <= n; ++i) {
    int t = ::t[i - 1];
    for (int d = 0; d < K; ++d) {
      Field &cur = A[i][d];

      for (int by = 0; by < t; ++by)
        cur.get(by * dx[d], by * dy[d]) = 1;

      int x = dx[d] * (t - 1);
      int y = dy[d] * (t - 1);

      for (int j : {-1, +1}) {
        int td = (d + j + K) % K;
        int tx = x + dx[td];
        int ty = y + dy[td];
        apply(cur, A[i - 1][td], tx, ty);
      }
    }
  }

  int ans = 0;
  Field &cur = A[n][0];
  //cur.print();
  for (int i = -T; i < T; ++i)
    for (int j = -T; j < T; ++j)
      ans += cur.get(i, j);

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}