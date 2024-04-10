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

long long T[100100];

void update(int idx,long long val){
	idx++;
	while(idx < 100100){
		T[idx] += val;
		idx += idx&-idx;
	}
}

long long query(int idx){
	idx++;
	long long ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

int a[100100];
int b[100100];
int d[100100];
long long qnt[100100];

int v[100100];

main(){

		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		for(int i=0;i<m;i++)
			scanf("%d%d%d",a+i,b+i,d+i), a[i]--, b[i]--;

		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--, y--;
			update(y+1,-1);
			update(x,1);
		}

		for(int i=0;i<m;i++)
			qnt[i] = query(i);

		memset(T,0,sizeof(T));

		for(int i=0;i<m;i++)
			update(b[i]+1, -qnt[i] * d[i]),
			update(a[i], qnt[i] * d[i]);

		for(int i=0;i<n;i++)
			printf("%I64d ",query(i)+v[i]);

		printf("\n");

}