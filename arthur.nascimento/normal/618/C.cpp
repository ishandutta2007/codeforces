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
#define maxn 600600
using namespace std;
typedef long long ll;

long long x[maxn];
long long y[maxn];

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];

	int a=0, b=1, c=-1;
	long long best;

	for(int i=2;i<n;i++){

		long long x1 = x[i]-x[a];
		long long y1 = y[i]-y[a];
		long long x2 = x[i]-x[b];
		long long y2 = y[i]-y[b];

		long long A = x1*y2-x2*y1;
		if(A < 0)
			A = -A;

		if(A == 0){

			if(x1*x2 < 0 || y1*y2 < 0)
				b = i;
			continue;
			
		}
		if(A < best || c == -1){
			best = A;
			c = i;
		}
	}

	printf("%d %d %d\n",a+1,b+1,c+1);

}