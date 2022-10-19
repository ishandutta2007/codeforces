#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
pii p[MAXN];
int a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
}

void solve() {
  sort(p, p + N);
  
  int third = N / 3 + (N % 3 == 2);
  for (int i = 0; i < third; i++) {
    b[p[i].second] = i;
    a[p[i].second] = p[i].first - i;
  }  
  for (int i = 0; i < third; i++) {
    a[p[N - 1 - i].second] = p[i].first;
    b[p[N - 1 - i].second] = p[N - 1 - i].first - p[i].first;
  }
  for (int i = third; i < N - third; i++)
    a[p[i].second] = p[i].first;
  
  puts("YES");
  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
  puts("");
  for (int i = 0; i < N; i++)
    printf("%d ", b[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}