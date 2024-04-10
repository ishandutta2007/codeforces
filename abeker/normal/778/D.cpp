#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 55;

int N, M;
char mat[MAXN][MAXN];
char tmp[MAXN][MAXN];
char mp[1 << 8];
vector <pii> res;

void rot(int x, int y) {
  res.push_back(pii(x, y));
  if (mat[x][y] == 'L') 
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        assert(mat[x + i][y + j] == "LR"[j]);
        mat[x + i][y + j] = "UD"[i];
      }
  else if (mat[x][y] == 'U') 
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        assert(mat[x + i][y + j] == "UD"[i]);
        mat[x + i][y + j] = "LR"[j];
      }
  else
    assert(0);
}

void dfs(int x, int y) {
  if (mat[x][y] == 'L') {
    if (mat[x + 1][y] != 'L') 
      dfs(x + 1, y);
    rot(x, y);
    return;
  }
  if (mat[x][y + 1] != 'U') 
    dfs(x, y + 1);
  rot(x, y);
}

vector <pii> get() {
  for (int i = 0; i < N; i++)
    scanf("%s", mat[i]);
  
  bool flag = false;
  
  if (N % 2) {
    flag = true;
    memcpy(tmp, mat, sizeof tmp);
    mp['U'] = 'L';
    mp['L'] = 'D';
    mp['D'] = 'R';
    mp['R'] = 'U';
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        mat[M - j - 1][i] = mp[tmp[i][j]];
    swap(N, M);
  }
  
  res.clear();
  
  for (int j = 0; j < M; j++)
    for (int i = 0; i < N; i += 2)
      if (mat[i][j] == 'L')
        dfs(i, j);
  
  if (flag) {
    swap(N, M);
    for (int i = 0; i < res.size(); i++)
      res[i] = pii(res[i].second, M - res[i].first - 2);
  }
  
  return res;
}

void output(vector <pii> v) {
  for (int i = 0; i < v.size(); i++)
    printf("%d %d\n", ++v[i].first, ++v[i].second);
}

int main() {
  scanf("%d%d", &N, &M);
  vector <pii> v1 = get();
  vector <pii> v2 = get();
  reverse(v2.begin(), v2.end());
  printf("%d\n", v1.size() + v2.size());
  output(v1);
  output(v2);
  return 0;
}