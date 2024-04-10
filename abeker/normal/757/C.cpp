#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXM = 1000005;
const int MOD = 1000000007;

int N, M;
vector <int> occ[MAXM];

int get() {
  int x;
  scanf("%d", &x);
  return x;
}

void load() {
  N = get();
  M = get();
  for (int i = 0; i < N; i++) 
    for (int g = get(); g; g--)
      occ[get()].push_back(i);
}

int solve() {
  sort(occ + 1, occ + M + 1);
  int curr = 0, sol = 1;
  for (int i = 1; i <= M; i++) {
    if (occ[i] != occ[i - 1])
      curr = 0;
    sol = (long long)sol * (++curr) % MOD;
  }
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}