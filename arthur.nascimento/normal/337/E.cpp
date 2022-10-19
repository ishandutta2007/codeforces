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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

map<long long,int> fatores[8];

int qnt[8];
long long v[8];
long long p[8];

int n;

int dp[1<<8];

int get(int mask,int pos){

	debug("get %d %d\n",mask,pos);
	
	if(dp[mask]+1)
		return dp[mask];

	int ret = 999999;

	if(pos == n){

		int t = 0;

		for(int i=0;i<n;i++)
			if(mask&(1<<i))
				t++;

		if(t == 1)
			return 0;
		else return 1;
	}



	for(int i=0;i<(1<<pos);i++){

		
		int ok = 1;

		for(int j=0;j<pos;j++)
			if((i&(1<<j)) && (mask&(1<<j)) == 0)
				ok = 0;

		if(!ok)
			continue;
		debug(":%d %d\n",mask,i);

		map<long long,int> mp = fatores[pos];

		ok = 1;
		debug("i = %d pos = %d\n",i,pos);

		for(int j=0;j<pos;j++)
			if(i&(1<<j))
				for(map<long long,int> :: iterator it = fatores[j].begin(); it != fatores[j].end(); it++){
					mp[it -> first] -= it -> second;
					if(mp[it -> first] < 0)
						ok = 0;}

		if(!ok)
			continue;

		int y = 0;

		for(int j=0;j<pos;j++)
			if(i&(1<<j))
				y += qnt[j];

		debug("mask = %d i = %d d = %d\n",mask,i,qnt[pos]-y);
		ret = min(ret,qnt[pos]-y+1+get((mask^i)|(1<<pos),pos+1));
		
	}	
	debug("dp[%d](%d) = %d\n--\n\n",mask,pos,ret);
	return dp[mask] = ret;
}

int primo(long long x){
	for(long long i=2;i*i<=x;i++)
		if(x%i == 0)
			return 0;
	return 1;}

main(){

	memset(dp,-1,sizeof(dp));

    int q = 0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
    	cin >> v[i];
		if(primo(v[i])){
			p[q++] = v[i];
			n--,i--;
			}
    	}

	if(!n){
		printf("%d\n",(q==1)?1:q+1);
		return 0;}

	int ans = q;

	for(int i=0;i<q;i++)
		for(int j=0;j<n;j++)
			if(v[j] % p[i] == 0){
					ans--;
					break;
				}

    sort(v,v+n);

    for(int i=0;i<n;i++){
	debug("\ni=%d\n",i);
	long long k = v[i];
	for(long long j=2;k != 1 && j*j <= k;j++)
		while(k % j == 0){
			fatores[i][j]++;
			qnt[i]++;
			k /= j;
			}
		if(k-1){
			fatores[i][k]++;
			qnt[i]++;
			}

    	}
for(int i=0;i<n;i++)debug("%d ",qnt[i]);debug("\n");
    printf("%d\n",ans+get(0,0));
    
}