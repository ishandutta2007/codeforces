#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 2500;
int const sigma = 7;
int up[5 + nmax][1 + sigma], down[5 + nmax][1 + sigma];
int upacc[1 + sigma];
int downacc[1 + sigma];
int temp[1 + sigma];

ll solve(int x, int y, int x2, int y2, int k, char (&v)[5 + nmax][5 + nmax]) {
  ll result = 0;
  int mid = (y + y2) / 2;

  for(int i = x; i <= x2; i++) {
    int ptr = 0;
    up[i][0] = mid + 1;
    for(int j = mid + 1; j <= y2 && ptr <= sigma; j++) {
      if(v[i][j] == '1') {
        ++ptr;
        if(ptr <= sigma)
          up[i][ptr] = j;
        else
          break;
      }
    }
    for(int j = ptr + 1; j <= sigma; j++)
      up[i][j] = y2 + 1;
    ptr = 0;
    down[i][0] = mid;
    for(int j = mid; y <= j && ptr <= sigma; j--) {
      if(v[i][j] == '1') {
        ++ptr;
        if(ptr <= sigma)
          down[i][ptr] = j;
        else
          break;
      }
    }
    for(int j = ptr + 1; j <= sigma; j++)
      down[i][j] = y - 1;
  }
  
  for(int i = x; i <= x2; i++) {
    for(int j = 0; j <= sigma; j++)
      upacc[j] = y2 + 1;
    for(int j = 0; j <= sigma; j++)
      downacc[j] = y - 1;
    downacc[0] = mid;
    upacc[0] = mid + 1;
    for(int j = i; j <= x2; j++) {
      int ptr = 1, ptr2 = 1;
      for(int h = 1; h <= sigma; h++) {
        if(upacc[ptr] < up[j][ptr2]) {
          temp[h] = upacc[ptr];
          ptr++;
        } else {
          temp[h] = up[j][ptr2];
          ptr2++;
        }
      }
      for(int h = 1; h <= sigma; h++)
        upacc[h] = temp[h];
      ptr = ptr2 = 1;
      for(int h = 1; h <= sigma; h++) {
        if(downacc[ptr] > down[j][ptr2]) {
          temp[h] = downacc[ptr];
          ptr++;
        } else {
          temp[h] = down[j][ptr2];
          ptr2++;
        }
      }
      for(int h = 1; h <= sigma; h++)
        downacc[h] = temp[h];
      
      /*
      if(i == 1 && j == 3)
        for(int h = 0; h <= k + 1; h++)
          std::cout << i << " " << j << " " << h << " " << downacc[h] << " " << upacc[h] << std::endl;
      //*/

      for(int h = 0; h <= k; h++)
        result += (downacc[h] - downacc[h + 1]) * (upacc[k - h + 1] - upacc[k - h]);
    }
  }
  return result;
}

char v[5 + nmax][5 + nmax], v2[5 + nmax][5 + nmax];

ll divide(int x, int y, int x2, int y2, int k) {
  if(x == x2 && y == y2) {
    if(k == (v[x][y] - '0'))
      return 1;
    return 0;
  } else if(x2 - x + 1 <= y2 - y + 1) {
    int mid = (y + y2) / 2;
    ll result = divide(x, y, x2, mid, k) + divide(x, mid + 1, x2, y2, k);
    return result + solve(x, y, x2, y2, k, v);
  } else {
    int mid = (x + x2) / 2;
    ll result = divide(x, y, mid, y2, k) + divide(mid + 1, y, x2, y2, k);
    return result + solve(y, x, y2, x2, k, v2);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    std::cin >> (1 + v[i]);
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      v2[j][i] = v[i][j];
  std::cout << divide(1, 1, n, m, k) << '\n';  
  return 0;
}