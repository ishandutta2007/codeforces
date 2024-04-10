#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXK = 300005;

int N, M, K;
char mat[MAXN][MAXN];
int a[MAXK], b[MAXK], c[MAXK], d[MAXK];
char e[MAXK];
ll sum[30][MAXN][MAXN];
int pref[30][MAXN][MAXN];
int cnt[30][MAXN][MAXN];
ll orig[MAXN][MAXN];

void load() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++)
    scanf("%s", mat[i] + 1);
  for (int i = 0; i < K; i++)
    scanf("%d%d%d%d %c", a + i, b + i, c + i, d + i, e + i);
}

template <typename T>
void build_sums(T tmp[MAXN][MAXN]) {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) 
      tmp[i][j] += tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1];
}

ll get_orig(int x1, int y1, int x2, int y2) {
  return orig[x2][y2] - orig[x2][y1 - 1] - orig[x1 - 1][y2] + orig[x1 - 1][y1 - 1];
}

ll get_sum(int k, int x1, int y1, int x2, int y2) {
  return sum[k][x2][y2] - sum[k][x2][y1 - 1] - sum[k][x1 - 1][y2] + sum[k][x1 - 1][y1 - 1];
}

void update_cnt(int k, int x1, int y1, int x2, int y2) {
  cnt[k][x1][y1]++;
  cnt[k][x2 + 1][y1]--;
  cnt[k][x1][y2 + 1]--;
  cnt[k][x2 + 1][y2 + 1]++;
}

void update_pref(int k, int x1, int y1, int x2, int y2) {
  pref[k][x1][y1] += k;
  pref[k][x2 + 1][y1] -= k;
  pref[k][x1][y2 + 1] -= k;
  pref[k][x2 + 1][y2 + 1] += k;
}

ll solve() {
  for (int i = 0; i < K; i++) {
    update_cnt(e[i] - 'a', a[i], b[i], c[i], d[i]);
    update_pref(e[i] - 'a', a[i], b[i], c[i], d[i]);
  }
  
  for (int k = 0; k < 26; k++) {
    build_sums(cnt[k]);
    build_sums(pref[k]);
  }
  
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int tot_cnt = 0;
      for (int k = 0; k < 26; k++) 
        tot_cnt += cnt[k][i][j];
      cnt[mat[i][j] - 'a'][i][j] += K - tot_cnt;
      pref[mat[i][j] - 'a'][i][j] += (K - tot_cnt) * (mat[i][j] - 'a');
    }
        
  for (int k = 1; k < 26; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) {
        pref[k][i][j] += pref[k - 1][i][j];
        cnt[k][i][j] += cnt[k - 1][i][j];
      }
          
  for (int k = 0; k < 26; k++) 
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        sum[k][i][j] = cnt[k][i][j] * k - pref[k][i][j] - (cnt[25][i][j] - cnt[k][i][j]) * k + pref[25][i][j] - pref[k][i][j];
  
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      orig[i][j] = sum[mat[i][j] - 'a'][i][j];  
  
  build_sums(orig);
  for (int k = 0; k < 26; k++)
    build_sums(sum[k]);
    
  ll sol = (ll)1e18;
  for (int i = 0; i < K; i++) 
    sol = min(sol, orig[N][M] - get_orig(a[i], b[i], c[i], d[i]) + get_sum(e[i] - 'a', a[i], b[i], c[i], d[i]));
  
  return sol;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}