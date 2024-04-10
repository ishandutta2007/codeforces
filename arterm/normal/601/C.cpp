#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int M = 100100;

int n, m;
ld p[M];

ld accumulate(ld *from, ld *to) {
  ld ans = 0.0;
  while (from != to)
    ans += *from, ++from;
  return ans;
}

void read() {
  cin >> n >> m;
  
  if (m == 1) {
    cout << 1.0 << endl;
    return;
  }

  p[0] = 1.0;
  
  int score = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    score += x;

    ld cur = accumulate(p + i * m, p + (i + 1) * m);
    
    for (int j = (i + 1) * m; j >= 0; --j) {
      ld bon = cur;
      if (j >= x)
        bon -= p[j - x];
      p[j] = bon / (m - 1);

      if (j >= 1)
        cur -= p[j - 1];
      if (j >= m + 1)
        cur += p[j - (m + 1)];
    }
  }

  ld prob = accumulate(p, p + score);

  cout << 1.0 + prob * (m - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(13);
  cout << fixed;
  read();
  return 0;
}