#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

long long ans[10100][4];

main(){

		long long n,k;
		scanf("%I64d%I64d",&n,&k);

		int a = 1;
		for(int i=0;i<n;i++){

			ans[i][0] = a;
			ans[i][1] = a+1;
			ans[i][2] = a+2;
			ans[i][3] = a+4;
			a = ans[i][3] + 2;

		}

		printf("%I64d\n",(a-2)*k);
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++)
				printf("%I64d ",k*ans[i][j]);
			printf("\n");
		}

}