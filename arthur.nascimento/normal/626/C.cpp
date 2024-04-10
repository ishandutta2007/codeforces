#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	int low = 0, up = (int)1e9;

	while(low != up){
		int mid = (low+up)/2;
		int q2 = (mid/2) - (mid/6);
		int q3 = (mid/3) - (mid/6);
		int q6 = (mid/6);

		int f = n - q2;
		if(f < 0) f = 0;
		q6 -= f;

		if(q6 < 0 || q3+q6 < m)
			low = mid+1;
		else
			up = mid;
	}

	printf("%d\n",low);

}