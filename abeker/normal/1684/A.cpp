#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    char num[15];
    scanf("%s", num);
    int len = strlen(num);
    printf("%c\n", len == 2 ? num[1] : *min_element(num, num + len));
  }
  return 0;
}