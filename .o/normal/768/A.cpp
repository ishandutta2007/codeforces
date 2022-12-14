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

int A[105000];
int C[105000];

int ans;

int main() {
  int n;
  scanf("%d", &n);
 for(int i = 0; i <n; i++) {
   scanf("%d", &A[i]);
 }
 sort(A, A+n);
 for(int i = 0 ;i < n;i ++){
   int c=0;
   if(A[i] > A[0]) c++;
   if(A[i] < A[n-1]) c++;
   if(c==2) ans++;
 }
 printf("%d\n", ans);
    return 0;
}