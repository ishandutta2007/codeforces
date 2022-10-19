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

struct p {
	int val,idx,ans;
	bool operator<(p comp)const{
		return val < comp.val;}
	};

p v[300300];

int ans[300300];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",&v[i].val);
			v[i].idx = i;}

		sort(v,v+n);

		v[0].ans = v[0].val;
		
		for(int i=1;i<n;i++)
			v[i].ans = max(1+v[i-1].ans, v[i].val);

		for(int i=0;i<n;i++)
			ans[v[i].idx] = v[i].ans;

		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);

	}