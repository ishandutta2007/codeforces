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

using namespace std;

vector<int> L[100100];

long long v[100100];


pll dfs(int x,int p){

	pll ret (0,0);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			pll k = dfs(*it,x);
			ret.first = max(ret.first, k.first);
			ret.second = max(ret.second, k.second);
		}

	v[x] += ret.first - ret.second;

	if(v[x] > 0)
		ret.second += v[x];
	if(v[x] < 0)
		ret.first -= v[x];

	return ret;

}

	

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;
			L[a].push_back(b);
			L[b].push_back(a);
		}

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i);

		pll k = dfs(0,0);

		printf("%I64d\n",k.first + k.second);

}