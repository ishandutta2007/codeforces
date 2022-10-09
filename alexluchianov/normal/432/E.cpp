#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100;
char v[1 + nmax][1 + nmax];
int n, m;

bool check(int i, int j, int k, char ch){
  if(i + k - 1 <= n && j + k - 1 <= m) {
    for(int x = 0; x < k; x++)
      if(v[i][j + x] != 0 || v[i + x][j] != 0)
        return 0;
    for(int x = 0; x < k; x++)
      if(v[i - 1][j + x] == ch || v[i + x][j - 1] == ch)
        return 0;
    if(v[i][j + k] == ch)
      return 0;
    return 1;
  } else
    return 0;
}

void place(int i, int j, int k, int ch){
  for(int x = i; x < i + k; x++)
    for(int y = j; y < j + k; y++)
      v[x][y] = ch;
}

int main()
{
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == 0){
        if(check(i, j, 1, 'a') == 1){
          int sz = 1;
          while(check(i, j, sz + 1, 'a') == 1)
            sz++;
          place(i, j, sz, 'a');
        } else if(check(i, j, 1, 'b') == 1){
          int sz = 1;
          while(check(i, j, sz + 1, 'b') == 1 && check(i, j + sz, 1, 'a') == 0)
            sz++;
          place(i, j, sz, 'b');
        } else if(check(i, j, 1, 'c') == 1) {
          int sz = 1;
          place(i, j, 1, 'c');
          while(check(i, j, sz + 1, 'c') == 1 && check(i, j + sz, 1, 'a') == 0 && check(i, j + sz, 1, 'b') == 0)
            sz++;
          place(i, j, sz, 'c');
        } else
          place(i, j, 1, 'd');
      }

  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++)
      cout << (char)(v[i][j] - 'a' + 'A');
    cout << '\n';
  }
  return 0;
}