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
#define mod 95542721
#define maxn 100100
using namespace std;
typedef long long ll;

main(){

	int n,k;
	scanf("%d%d",&n,&k);
	if(k >= (n*n-n)/2){
		printf("no solution\n");
		return 0;
	}

	for(int i=0;i<n;i++)
		printf("0 %d\n",i);

}