#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
int perm[MAXN];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
  int parity = 0;
  for (int i = 1; i <= N; i++)
    for (; perm[i] != i; parity ^= 1)
      swap(perm[i], perm[perm[i]]);
  puts((parity + N) % 2 ? "Um_nik" : "Petr");
  return 0;
}