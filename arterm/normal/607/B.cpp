#include <bits/stdc++.h>

using namespace std;

const int M = 505;

int n;
int s[M];
int d[M][M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
}

void din() {
  for (int i = 0; i < n; ++i) {
    d[i][i + 1] = 1;
  }

  for (int len = 2; len <= n; ++len)
    for (int i = 0; i + len <= n; ++i) {
      int j = i + len;
      d[i][j] = j - i;
      
      d[i][j] = min(d[i][j], d[i][j - 1] + 1);
      for (int x = i; x < j - 1; ++x)
        if (s[x] == s[j - 1])
          d[i][j] = min(d[i][j], d[i][x] + (x + 1 == j - 1 ? 1 : d[x + 1][j - 1]));
    }
  
  cout << d[0][n] << endl;
}     


int main() {
  ios_base::sync_with_stdio(false);
  read();
  din();
  return 0;
}