#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 1005

using namespace std;
typedef long long ll;

bool on[maxn];
int n, k;
int R(int x) {
  return n - x - (n + x - 1) / x + 1;
}
int main() {
  scanf("%d", &n);
  if (n <= 3) {
    puts("0");
    fflush(stdout);
    return 0;
  }
  k = sqrt(n);
  if (R(k + 1) > R(k)) k++;
  while (true) {
    vector<int> move;
    for (int i = 0; (int)move.size() < k && i < n; i++) {
      if (i % k && !on[i]) {
        move.push_back(i + 1);
        on[i] = true;
      }
    }
    if ((int)move.size() < k) break;
    printf("%d ", int(move.size()));
    for (auto i : move) printf("%d ", i);
    puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    x--;
    for (int i = 0; i < k; i++) on[(x + i) % n] = false;
  }
  puts("0");
  fflush(stdout);
  return 0;
}