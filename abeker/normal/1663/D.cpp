#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int rating;
  char contest[3];
  scanf("%s%d", contest, &rating);
  switch (contest[1]) {
    case 'B':
      return rating < 2000;
    case 'R':
      return rating < 2800;
    case 'G':
      return rating >= 1200;
    case 'H':
      return true;
    default:
      assert(false);
  }
}

int main() {
  puts(solve() ? "yes" : "no");
  return 0;
}