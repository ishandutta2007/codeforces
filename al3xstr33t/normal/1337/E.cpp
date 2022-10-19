#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

const int maxN = 3011;
const int mod = 998244353;

int n, m;
char s[maxN], target[maxN];
int dp[maxN][maxN], answer;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main()
{
  //freopen("test.in", "r", stdin);

  scanf("%s\n%s", s, target);
  n = strlen(s);
  m = strlen(target);

  for (int i = 0; i < m; i++)
    if (target[i] == s[0])
      dp[i][i] = 2;

  for (int i = m; i < n; i++) { 
    target[i] = '.';
    dp[i][i] = 2;
  }

  for (int i = n - 1; i >= 0; i--) {
    int idx = 1;

    for (int j = i + 1; j < n; j++, idx++) {
      if (target[i] == '.' || target[i] == s[idx])
        add(dp[i][j], dp[i + 1][j]);
      if (target[j] == '.' || target[j] == s[idx])
        add(dp[i][j], dp[i][j - 1]);
    }
  } 

  for (int i = m - 1; i < n; i++)
    add(answer, dp[0][i]);

  printf("%d\n", answer);

  /*
  for (int i = 0; i < n; i++) {
    cerr << i << ": ";
    for (int j = i; j < n; j++) cerr << dp[i][j] << ' ';
    cerr << '\n';
  }
  */


  return 0;
}