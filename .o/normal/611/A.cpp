#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int x; char s[100];

int main() {
scanf("%d%*s%s",&x,s);int c=0;
if(!strcmp(s,"week")){
 int d = 5;
 for(int i = 0; i < 366; i++) {
  if(d == x) ++c; d = d%7 + 1;
 }
}else {
 int d[] = {31,29,31,30,31,30,31,31,30,31,30,31};
 for(int i=0;i<12;i++) if(x <= d[i]) ++c;
}
printf("%d\n",c);
  
    return 0;
}