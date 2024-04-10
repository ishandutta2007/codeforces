#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<char, int> cnt;

const int M = 303;

bool d[M][M][M];

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;

  for (char c : s)
    cnt[c]++;


  d[cnt['R']][cnt['G']][cnt['B']] = true;
  
  for (int s = M - 1; s >= 0; --s)
    for (int i = 0; i <= s; ++i)
      for (int j = 0; j <= s; ++j) {
        int k = s - i - j;
        if (k >= M)
          continue;

        bool cur = d[i][j][k];

        if (i > 0 && j > 0)
          d[i - 1][j - 1][k + 1] |= cur;
        if (j > 0 && k > 0)
          d[i + 1][j - 1][k - 1] |= cur;
        if (k > 0 && i > 0)
          d[i - 1][j + 1][k - 1] |= cur;

        if (i >= 2)
          d[i - 1][j][k] |= cur;
        if (j >= 2)
          d[i][j - 1][k] |= cur;
        if (k >= 2)
          d[i][j][k - 1] |= cur;
    }
  
  string ans;

  if (d[1][0][0])
    ans.push_back('R');
  if (d[0][1][0])
    ans.push_back('G');
  if (d[0][0][1])
    ans.push_back('B');

  sort(ans.begin(), ans.end());

  cout << ans << endl;
}