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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

int N; lf a, D;
lf mx;
int main() {
	scanf("%d%lf%lf", &N, &a, &D);
	while(N--) {
		lf t, v; scanf("%lf%lf", &t, &v);
		lf ret = 0;

		lf tri = v * (v / a) / 2;
		lf dst = D;
		if(dst <= tri) { //   
			ret = sqrt(2 * dst / a);
		}else {
			ret = (v / a);
			dst -= tri;
			ret += dst / v;
		}

		ret += t;
		mx = max(mx, ret);
		printf("%.10lf\n", mx);
	}
	return 0;
}