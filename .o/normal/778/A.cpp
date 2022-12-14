#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int L_ = 200500;

char P[L_], T[L_];
int PN, TN;
int A[L_];

bool good (int x) {
  vector<bool> chk(L_+1, true);
  for(int i = 1; i <= x; i++) chk[A[i]] = false;
  for(int i = 1, j = 1; i <= TN; i++) {
    if(chk[i]) {
      if(j <= PN && P[j] == T[i]) j += 1;
    }
    if(j > PN) return true;
  }
  return false;
}

int main() {
  scanf("%s%s", T+1, P+1);
  PN = strlen(P+1);
  TN = strlen(T+1);
  for(int i = 1; i <= TN; i++) {
    scanf("%d", &A[i]);
  }

  int low = 0, high = TN, ans = -1;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(good(mid)) {
       ans = mid;
       low = mid + 1;
    }else {
      high = mid - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}