#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 200;
ll const inf = 1000000000000000000LL;
int mat[5 + nmax][5 + nmax];
ll sum[5 + nmax][5 + nmax];

ll get_sum(int x, int x2, int y, int y2) {
  if(x <= x2 && y <= y2){
    return sum[x2][y2] - sum[x - 1][y2] - sum[x2][y - 1] + sum[x - 1][y - 1];
  }

  return 0;
}

ll dp[5 + nmax][5 + nmax];
int bestSplit[5 + nmax][5 + nmax];
int answer[5 + nmax];

void build(int x, int y, int parent) {
  if(x < y) {
    int mid = bestSplit[x][y];
    answer[mid] = parent;
    build(x, mid -1 , mid);
    build(mid + 1, y, mid);
  } else if(x == y)
    answer[x] = parent;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1;j <= n; j++)
      std::cin >> mat[i][j];
  for(int i = 1;i <= n; i++)
    for(int j = 1; j <= n; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
  
  for(int i = n; 1 <= i; i--)
    for(int j = i + 1; j <= n; j++) {
      dp[i][j] = inf;
      for(int h = i; h <= j; h++) {
        ll newdp = 
                   dp[i][h - 1] + dp[h + 1][j] +
                   get_sum(i, j, 1, i - 1) +     
                   get_sum(i, j, j + 1, n) - 
                   get_sum(h, h, 1, i - 1) -
                   get_sum(h, h, j + 1, n) + get_sum(i, h - 1 , h + 1, j) * 2 + get_sum(h, h, i, j);
        if(newdp < dp[i][j]) {
          dp[i][j] = newdp;
          bestSplit[i][j] = h;
        }
        
      }
    }
  build(1, n, 0);

  for(int i = 1; i <= n; i++)
    std::cout << answer[i] << " ";
  std::cout << '\n';
  return 0;
}