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
 
using namespace std;
typedef long long ll;

map<int,int> c1, c2;

int main() {
 int n;
 scanf("%d", &n);
 while(n--) {
  int x, y; scanf("%d%d",&x,&y);
  c1[x-y]++; c2[x+y]++;
 }
 ll ans =0 ;
 for(auto it : c1) ans += (ll)it.second * (it.second - 1) / 2;
 for(auto it : c2) ans += (ll)it.second * (it.second - 1) / 2;
 printf("%I64d\n",ans);
 return 0;
}