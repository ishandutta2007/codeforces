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
#define maxn 200200
#define mod 1000000007

typedef long long ll;
using namespace std;

main(){

	int n,d,h;
	scanf("%d%d%d",&n,&d,&h);

	if(d >= n || d > 2*h || h > d){
		printf("-1\n");
		return 0;
	}

	if(d == h){

		if(d == 1){
			if(n == 2){
				printf("1 2\n");
				return 0;
			}
			else {
				printf("-1\n");
				return 0;
			}
		}

		for(int i=1;i<=d;i++)
			printf("%d %d\n",i,i+1);
		for(int i=d+2;i<=n;i++)
			printf("2 %d\n",i);
		return 0;
		
	}

	for(int i=1;i<=h;i++)
		printf("%d %d\n",i,i+1);
	int qnt = d-h;
	int cur = h+2;
	printf("1 %d\n",cur);
	for(int i=0;i<qnt-1;i++){
		printf("%d %d\n",cur,cur+1);
		cur++;
	}
	cur++;
	while(cur <= n){
		printf("1 %d\n",cur);
		cur++;
	}
	
}