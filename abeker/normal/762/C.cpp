#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100005;

int N, M;
char a[MAXN], b[MAXN];
int pref[MAXN], suff[MAXN];

void load() {
  scanf("%s%s", a, b);
}

int check(int len) {
  for (int i = 0; i + len + 1 < M; i++)
    if (pref[i] < suff[i + len + 1]) 
      return i + 1;
  if (suff[len] >= 0) 
    return 0;
  if (pref[M - len - 1] < N) 
    return M - len;
  return -1;
}

void solve() {
  N = strlen(a);
  M = strlen(b);
  
  int pos = 0;
  for (int i = 0; i < M; i++) {
    while (pos < N && a[pos] != b[i])
      pos++;
    pref[i] = pos++;
  }  
  
  pos = N - 1;
  for (int i = M - 1; i >= 0; i--) {
    while (pos >= 0 && a[pos] != b[i])
      pos--;
    suff[i] = pos--;
  }
  
  int lo = 0, hi = M;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid) != -1)
      hi = mid;
    else 
      lo = mid + 1;
  }
  
  if (lo == M) {
    puts("-");
    return;
  }
  
  pos = check(lo);
  for (int i = 0; i < M; i++)
    if (i < pos || i >= pos + lo)
      printf("%c", b[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}