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

int main() {
 int n; scanf("%d", &n);
 vector<int> a(n); ll ans=0;
 for(int i=0;i<n;i++) scanf("%d",&a[i]),ans+=a[i];
 sort(a.begin(),a.end());
 for(int i=0;i<n;i++){
  if(ans%2==1 && a[i]%2==1) {
   ans -= a[i]; break;
  }
 }
 printf("%I64d",ans);
 return 0;
}