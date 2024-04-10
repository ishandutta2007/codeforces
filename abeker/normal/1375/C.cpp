#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> v(N);
    for (int i = 0; i < N; i++)
      scanf("%d", &v[i]);
    puts(v[0] <= v[N - 1] ? "YES" : "NO");
  }
  return 0;
}