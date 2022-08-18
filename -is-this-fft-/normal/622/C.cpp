#include <stdio.h>
#include <algorithm>

const int MAX_L = 200005;
const int INF = 1023456789;

using namespace std;

int arr [MAX_L];
int nxt [MAX_L];

int main () {
  int length, queryc;
  scanf("%d %d", &length, &queryc);

  for (int i = 1; i <= length; ++i) {
    scanf("%d", &arr[i]);
  }

  int cnext = INF;
  for (int i = length; i > 0; --i) {
    nxt[i] = cnext;
    if (i > 1 && arr[i] != arr[i - 1]) {
      cnext = i;
    }
  }

  for (int i = 0; i < queryc; ++i) {
    int left, right, target;
    scanf("%d %d %d", &left, &right, &target);

    if (arr[left] != target) {
      printf("%d\n", left);
    } else if (nxt[left] > right) {
      printf("-1\n");
    } else {
      printf("%d\n", nxt[left]);
    }
  }
}