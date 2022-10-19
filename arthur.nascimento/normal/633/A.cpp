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
#define maxn 100100

typedef long long ll;
using namespace std;

main(){

	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ok = 0;
	for(int i=0;i<maxn;i++){
		if((ll)i*a > c)
			continue;
		int u = c - i*a;
		if(u%b == 0)
			ok = 1;
	}
	if(ok)
		printf("Yes\n");
	else
		printf("No\n");

}