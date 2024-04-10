#include <iostream>
#include <fstream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

int const kmax = 100;
int comb[5 + nmax][5 + kmax];

void computecomb(){
  comb[0][0] = 1;
  for(int i = 1;i <= nmax; i++){
    comb[i][0] = 1;
    for(int j = 1; j <= MIN(i, kmax); j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modulo;
  }
}

int v[5 + nmax];
int sum[5 + kmax][5 + nmax];

void addinterval(int level, int x, int y, int start, int k){
  if(x == y) {
    sum[level][x] += comb[start][k];
    if(modulo <= sum[level][x])
      sum[level][x] -= modulo;

    sum[level][x + 1] -= comb[start][k];

    if(sum[level][x + 1] < 0)
      sum[level][x + 1] += modulo;
    return ;
  }

  if(0 <= k){
    sum[level][x] += comb[start][k];
    if(modulo <= sum[level][x])
      sum[level][x] -= modulo;

    sum[level][y + 1] -= comb[start + y - x][k];

    if(sum[level][y + 1] < 0)
      sum[level][y + 1] += modulo;

    if(0 < k) {
      addinterval(level + 1, x + 1, y, start, k - 1);
    }
  } else
    return ;
}

int main()
{
  int n, m;
  cin >> n >> m;
  computecomb();
  for(int i = 1;i <= n; i++){
    int curr;
    cin >> curr;
    sum[0][i] += curr;
    if(modulo <= sum[0][i])
      sum[0][i] -= modulo;

    sum[0][i + 1] -= curr;
    if(sum[0][i + 1] < 0)
      sum[0][i + 1] += modulo;
  }
  for(int i = 1;i <= m; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    addinterval(0, x, y, k, k);
  }
  for(int level = kmax; 0 <= level; level--){
    for(int i = 1;i <= n; i++) {
      sum[level][i] += (sum[level][i - 1] + sum[level + 1][i]) % modulo;
      if(modulo <= sum[level][i])
        sum[level][i] -= modulo;
    }
  }
  for(int i = 1;i <= n; i++)
    cout << sum[0][i] << " ";
  return 0;
}
/*
10 2
1 2 3 4 5 0 0 0 0 0
1 6 1
6 10 2
*/