#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

#define next dlsafsadfasdf

const int M = 100100;
const int A = 30;
const int N = 255;
const int inf = 1e9;
const int LEN = N * N * N;

int d[N * N * N];
int next[M][A];
int n;
string s;
int q;
vector<int> t[3];
int by[] = {1, N, N * N};
int len[] = {0, 0, 0};


void read() {
  cin >> n >> q;
  cin >> s;
}

void uin(int &x, int y) {
  x = min(x, y);
}

void relax(int enc, int b, int i) {
    assert(i > 0);

    for (int k = 0; k < 3; ++k)
      if (by[k] == b) {
        int from = enc - b;
        if (d[from] < n)
          uin(d[enc], next[d[from]][t[k][i - 1]]);
        return;
      }

    assert(false);
  };

void kill() {
  for (int i = 0; i < A; ++i)
    next[n][i] = inf;

  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < A; ++c)
      next[i][c] = next[i + 1][c];
    
    int cur = s[i] - 'a';
    next[i][cur] = i + 1;
  }

  fill(d, d + LEN, inf);
  d[0] = 0;


  while (q--) {
    char type;
    int at;
    cin >> type >> at;
    --at;

    if (type == '+') {
      char c;
      cin >> c;
      int cur = c - 'a';

      int leni, lenj;
      int byi, byj;

      if (at == 0) {
        leni = len[1];
        lenj = len[2];

        byi = by[1];
        byj = by[2];
      } else if (at == 1) {
        leni = len[0];
        lenj = len[2];

        byi = by[0];
        byj = by[2];
      } else {
        leni = len[0];
        lenj = len[1];

        byi = by[0];
        byj = by[1];
      }

      len[at]++;
      t[at].push_back(cur);

      for (int i = 0; i <= leni; ++i)
        for (int j = 0; j <= lenj; ++j) {
          int enc = i * byi + j * byj + len[at] * by[at];
          
          if (i > 0)
            relax(enc, byi, i);
          if (j > 0)
            relax(enc, byj, j);
          
          relax(enc, by[at], len[at]);

        }

    } else {
      int leni, lenj;
      int byi, byj;

      if (at == 0) {
        leni = len[1];
        lenj = len[2];

        byi = by[1];
        byj = by[2];
      } else if (at == 1) {
        leni = len[0];
        lenj = len[2];

        byi = by[0];
        byj = by[2];
      } else {
        leni = len[0];
        lenj = len[1];

        byi = by[0];
        byj = by[1];
      }

      for (int i = 0; i <= leni; ++i)
        for (int j = 0; j <= lenj; ++j) {
          int enc = i * byi + j * byj + len[at] * by[at];
          d[enc] = inf;
        }

      t[at].pop_back();
      len[at]--;
    }

    bool ok = d[len[0] * by[0] + len[1] * by[1] + len[2] * by[2]] < inf;
    cout << (ok ? "YES" : "NO") << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}