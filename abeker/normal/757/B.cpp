#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int cnt[MAXN];

int main() {
  scanf("%d", &N);
  while (N--) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  
  int sol = 1;
  for (int i = 2; i < MAXN; i++) {
    int sum = 0;
    for (int j = i; j < MAXN; j += i)
      sum += cnt[j];
    sol = max(sol, sum);
  }
  
  printf("%d\n", sol);
  
  return 0;
}