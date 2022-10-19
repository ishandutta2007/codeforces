#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<unsigned long long,unsigned long long>
#define pdd pair<double,double>
#define eps 0

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int n;

char dp[24][1<<16];
char dp2[24][1<<16][2];

int v[25];

int get(int,int);

int get2(int q1,int mask,int t){

	if(dp2[q1][mask][t]+1)
		return dp2[q1][mask][t];

	debug("get2 %d %d %d\n",q1,mask,t);

	if(mask == 0){
		if(t)
			return q1 >= 1;
		return q1 >= 2;
	}

	if(t == 1 && get(q1,mask))
		return dp2[q1][mask][t] = 1;

	int qnt = 0, maior = -1;

	for(int i=0;i<n;i++)
		if(mask & (1<<i))
			qnt++;

	if(qnt+q1 == 0)
		return dp2[q1][mask][t] = 0;

	for(int i=0;i<n;i++)
		if(mask & (1<<i))
			if(maior == -1 || v[i] > v[maior])
				maior = i;

	if(mask == 0 && q1 >= 2)
		return dp2[q1][mask][t] = 1;
	if(mask == 0)
		return dp2[q1][mask][t] = 0;

	for(int i=0;i<(1<<n);i++){

		if((mask|i) ^ mask)
			continue;

		if(i & (1<<maior) == 0)
			continue;

		for(int j=0;j<=q1;j++)
			if(get(j,i) && get2(q1-j,mask^i,1))
				return dp2[q1][mask][t] = 1;

	}

	return dp2[q1][mask][t] = 0;

}

	

int get(int q1,int mask){

	if(dp[q1][mask]+1)
		return dp[q1][mask];

	if(mask == 0 && q1 == 0)
		return 0;
	if(mask == 0 && q1 == 1)
		return 1;
	if(mask == 0)
		return 0;

	debug("get %d %d\n",q1,mask);

	int qnt = 0, maior = -1;

	for(int i=0;i<n;i++)
		if(mask & (1<<i)){
			qnt++;
			if(maior == -1 || v[i] > v[maior])
				maior = i;
		}

	

	if(qnt+q1 != v[maior])
		return dp[q1][mask] = 0;

	if(qnt == 0)
		return dp[q1][mask] = 0;


	if(get2(q1,mask^(1<<maior),0))
		return dp[q1][mask] = 1;
	else
		return dp[q1][mask] = 0;
	
}

bool comp(int a,int b){
	return a > b;}

main(){

		scanf("%d",&n);

		int q1 = 0;

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			if(v[i] == 1)
				q1++;
		}

		if(n-q1 > 15){
			printf("NO\n");
			return 0;
		}

		sort(v,v+n,comp);

		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));

		n -= q1;
		if(get(q1,(1<<n)-1))
			printf("YES\n");
		else
			printf("NO\n");

}