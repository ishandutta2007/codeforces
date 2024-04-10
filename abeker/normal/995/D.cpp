#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, R;
  scanf("%d%d", &N, &R);
  vector <int> c(1 << N);
  for (auto &it : c)
    scanf("%d", &it);
  long long sum = accumulate(c.begin(), c.end(), 0ll);
  auto answer = [&]() {
    printf("%lf\n", (double)sum / (1 << N));
  };
  answer();
  while (R--) {
    int x;
    scanf("%d", &x);
    sum -= c[x];
    scanf("%d", &c[x]);
    sum += c[x];
    answer();
  }
  return 0;
}