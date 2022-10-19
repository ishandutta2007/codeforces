#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;

const int MAXN = 505;
const int LOG = 61;
const ll INF = (ll)1e18;

int N, M;
int adj[MAXN][MAXN][2];
int bio[MAXN][2];
ll dp[MAXN][2];

struct matrix {
  int m[MAXN][MAXN];
  matrix() {
    memset(m, 0, sizeof m);
  }
};

matrix operator *(matrix A, matrix B) {
  matrix C;
  bitset <MAXN> row[MAXN], col[MAXN];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (A.m[i][j])
        row[i].set(j);
      if (B.m[i][j])
        col[j].set(i);
    }
      
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      C.m[i][j] = (row[i] & col[j]).any();
  
  return C;
}

matrix mat[LOG][2];

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    adj[--u][--v][t] = 1;
  }
}

ll dfs(int city, int curr) {
  ll &ref = dp[city][curr];
  if (bio[city][curr] == 1)
    return ref = INF;
  if (bio[city][curr] == 2)
    return ref;
  bio[city][curr] = 1;
  ref = 0;
  int maks = -1;
  for (int i = 0; i < LOG; i++)
    for (int j = 0; j < N; j++)
      if (mat[i][curr].m[city][j])
        maks = i;
  if (maks == -1) {
    bio[city][curr] = 2;
    return ref;
  }
  for (int i = 0; i < N; i++)
    if (mat[maks][curr].m[city][i]) 
      ref = max(ref, dfs(i, curr ^ 1));
  bio[city][curr] = 2;
  if (ref <= INF) 
    ref += 1ll << maks;
  return ref;
}

ll solve() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) 
      for (int k = 0; k < 2; k++)
        mat[0][k].m[i][j] = adj[i][j][k];
  
  for (int i = 1; i < LOG; i++)
    for (int j = 0; j < 2; j++)
      mat[i][j] = mat[i - 1][j] * mat[i - 1][j ^ 1];  
  
  ll sol = dfs(0, 0);
  
  return sol > INF ? -1 : sol;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}