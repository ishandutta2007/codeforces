#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 5050;
const int T = 5025;
const ll inf = 1e18;

ll n, s, e;
ll x[M], a[M], b[M], c[M], d[M];
ll h[M][M];

void readarr(ll *x) {
  for (int i = 0; i < n; ++i)
    cin >> x[i];
}

void read() {
  cin >> n >> s >> e;
  --s, --e;
  readarr(x);
  readarr(a);
  readarr(b);
  readarr(c);
  readarr(d);

  for (int i = 0; i < n; ++i) {
    d[i] -= x[i];
    a[i] += x[i];
    c[i] += x[i];
    b[i] -= x[i];
  }
}

int diff = 0;

void relax(int at, int bal, ll val) {
  h[at][bal] = min(h[at][bal], val);
}

void kill() {
  for (int i = 0; i < M; ++i) {
    fill(h[i], h[i] + M, inf);
  }

  h[0][0] = 0;


  for (int i = 0; i < n; ++i) { 
    int old = diff;

    for (int bal = 0; bal <= T; ++bal) {
      if (bal == 0 && bal + old == 0 && i != 0)
        continue;

      ll cur = h[i][bal];

      if (cur >= inf / 2)
        continue;

      if (i == s) {
        if (bal + diff > 0)
          relax(i + 1, bal, cur + c[i]);
        relax(i + 1, bal + 1, cur + d[i]);
      }

      if (i == e) {
        relax(i + 1, bal, cur + b[i]);
        if (bal > 0)
          relax(i + 1, bal - 1, cur + a[i]);
      }

      if (i != s && i != e) {
        relax(i + 1, bal + 1, cur + d[i] + b[i]);
        if (bal > 0)
          relax(i + 1, bal, cur + d[i] + a[i]);
        if (bal + diff > 0)
          relax(i + 1, bal, cur + c[i] + b[i]);
        if (bal + diff > 0 && bal > 0)
          relax(i + 1, bal - 1, cur + c[i] + a[i]);
      }
        
    }
    
    if (i == s) {
      diff--;
    }
    if (i == e) {
      diff++;
    }



  }

  cout << h[n][0] << endl;

}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}