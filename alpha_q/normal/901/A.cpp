#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int h, n, a[N];

int main() {
  scanf("%d", &h);
  for (int i = 0; i <= h; ++i) {
    scanf("%d", a + i);
    // n += a[i];
  }
  assert(a[0] == 1);
  int at = -1;
  for (int i = 0; i < h; ++i) {
    if (a[i] > 1 and a[i + 1] > 1) {
      at = i;
      break;
    }
  }
  if (at == -1) {
    puts("perfect");
    return 0;
  }
  
  int last;
  puts("ambiguous");

  printf("0");
  last = n = 1;
  for (int i = 1; i <= h; ++i) {
    int x = a[i];
    while (x--) {
      ++n;
      printf(" %d", last);
    } 
    last = n;
  } 
  puts("");

  printf("0");
  last = n = 1;
  for (int i = 1; i <= at; ++i) {
    int x = a[i];
    while (x--) {
      ++n;
      printf(" %d", last);
    } 
    last = n;
  }
  ++n;
  printf(" %d", last - 1);
  int z = a[at + 1] - 1;
  while (z--) {
    ++n;
    printf(" %d", last);
  }
  last = n;
  for (int i = at + 2; i <= h; ++i) {
    int x = a[i];
    while (x--) {
      ++n;
      printf(" %d", last);
    } 
    last = n;
  }
  puts("");
  return 0;
}