#include <bits/stdc++.h>

using namespace std;

map<int, int> go;

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    int x, y; scanf("%d%d", &x, &y);
    go[x] = y;
  }
  int M; scanf("%d", &M);
  while(M--) {
    int x, y; scanf("%d%d", &x, &y);
    go[x] = max(go[x], y);
  }
  
  long long sum = 0;
  for(auto it : go) sum += it.second;
  printf("%lld\n", sum);
  
}