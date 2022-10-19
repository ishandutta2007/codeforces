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
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007
 
using namespace std;

vector<int> L[100100];
long long qnt[100100];
long long profmax;

long long sum[100100];
long long sum2[100100];

long long get(int a,int b){

	long long sa = sum[b] - (a ? sum[a-1] : 0);

	long long sb = sum2[b] - (a ? sum2[a-1] : 0);

	return sb - ((long long)(profmax - b)) * sa;

}

long long getn(int a,int b){

	if(a > b)
		return 0;
	return sum[b] - (a ? sum[a-1] : 0);
}

void dfs(int x,int p,int prof){

	qnt[prof]++;
	profmax = max(profmax, (long long)prof);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			dfs(*it,x,prof+1);

}


main(){

		int n,k,p;
		scanf("%d%d%d",&n,&k,&p);

		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;
			L[a].push_back(b);
			L[b].push_back(a);

		}

		dfs(0,0,0);

		qnt[0] = 0;
		sum[0] = qnt[0];

		for(int i=1;i<=profmax;i++)
			sum[i] = sum[i-1] + qnt[i];

		sum2[0] = qnt[0] * profmax;

		for(int i=1;i<=profmax;i++)
			sum2[i] = sum2[i-1] + qnt[i] * (profmax-i+1);

		long long ans = 1;

		debug("profmax = %d\n",profmax);

		for(int i=0;i<=profmax;i++)
			debug("%d ",qnt[i]);
		debug("\n");

		for(int i=1;i<=profmax;i++){

			if(get(0,i-1) <= p){
				ans = max(ans,getn(0,i));
				if(ans == 3)
					debug("!!! %d\n",i);
				continue;
			}

			int a = 0;
			int b = i-1;

			while(a != b){

				int m = (a+b+1)/2;

				if(get(m,i-1) <= p)
					b = m-1;
				else	
					a = m;

			}

			

			long long scur = getn(a+1,i);

			long long pcur = p - get(a+1,i-1);
			long long price = i-a;

			//debug("i=%d a=%d scur = %lld pcur = %lld price = %lld\n",i,a,scur,pcur,price);

			scur += pcur / price;

			ans = max(ans, scur);

			if(scur == 3){
				debug("!! %d\n",i);
				}

		}

		printf("%I64d\n",min(ans,(long long)k));

	}