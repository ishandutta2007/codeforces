# include <bits/stdc++.h>

using namespace std;

int n;
int good;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    good |= (x == 1);
  }
  printf("%d", good ? -1 : 1);
  return 0;
}