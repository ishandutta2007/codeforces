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

const int N_ = 100500;
int M, N; char S[N_];
bool ans[N_];
int cnt[26];

int main() {
 scanf("%d%s", &M, S+1); N = strlen(S+1);

 for(int i = 1; i <= N; i++) ans[i] = true;
 for(int c = 25; c >= 0; c--) {
  int cur = 0;
  bool good = true;
  for(int i = 1, j = -1; i <= N; i++) {
   if(S[i] == c + 'a') ans[i] = false, j = i;
   if(ans[i]) cur += 1;
   if(i > M && ans[i - M]) cur -= 1;
   if(cur == 0 && i >= M) {
     assert(j > -1); ans[j] = true; cur += 1;
     good = false;
   }
  }
  if(!good) break;
 }

 for(int i = 1; i <= N; i++) if(ans[i]) cnt[S[i] - 'a'] += 1;
 for(int c = 0; c < 26; c++) while(cnt[c]--) putchar(c + 'a');
 return 0;
}