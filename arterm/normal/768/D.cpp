#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 1010;
const int M = 10010;
const ld eps = 1e-8;

int k, q;
ld d[M][N];

void read() {
  cin >> k >> q;
}

void pre() {
  d[0][0] = 1.;
  for (int i = 0; i + 1 < M; ++i)
    for (int j = 0; j <= k; ++j) {
      ld p = 1. * j / k;
      ld cur = d[i][j];
      d[i + 1][j] += p * cur;
      d[i + 1][j + 1] += (1 - p) * cur;
    }
}

void kill() {
  //for (int i = 0; i < 10; ++i) {
    //int j = M - 1 - i;
    //cerr << j << ": " << d[j][k] << endl;
  //}

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    ld t = (x - eps) / 2000.;
    
    int j = 0;
    while (j < M && d[j][k] < t)
      ++j;

    assert (j < M);
    cout << j << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  pre();
  kill();

}