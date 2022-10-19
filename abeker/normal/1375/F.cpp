#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll a[3];
 
void play(ll y) {
  printf("%lld\n", y);
  fflush(stdout);
  int pile;
  scanf("%d", &pile);
  if (!pile)  
    exit(0);
  a[--pile] += y;
}
 
int main() {
  for (int i = 0; i < 3; i++)
    scanf("%lld", a + i);
  puts("First");
  fflush(stdout);
  play(1e9);
  play(3 * *max_element(a, a + 3) - accumulate(a, a + 3, 0ll));
  play((*max_element(a, a + 3) - *min_element(a, a + 3)) / 2);
  return 0;
}