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

long long T[200200];

void update(int idx,int val){
	idx++;
	while(idx < 200200){
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

struct div_ {
	int a,b;
	div_(int a=0,int b=0): a(min(a,b)), b(max(a,b)) {}
	bool operator<(div_ comp)const{
		return a < comp.a;}
}

D[20*200200];

struct query {
	int a,b,idx;
	bool operator<(query comp)const{
		return a < comp.a;}
}

Q[200200];


int v[200200];
int pos[200200];

long long ans[200200];

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			pos[v[i]] = i;
		}

		int qnt = 0;

		for(int i=1;i<=n;i++)
			for(int j=2*i;j<=n;j+=i)
				D[qnt++] = div_(pos[i],pos[j]);

		sort(D,D+qnt);

		for(int i=0;i<q;i++)
			scanf("%d%d",&Q[i].a,&Q[i].b),
			Q[i].a--, Q[i].b--, Q[i].idx = i;

		sort(Q,Q+q);

		for(int i=0;i<qnt;i++)
			update(D[i].b,1);

		int pd = 0;
		int pq = 0;

		while(pq < q){

			while(pd < qnt && D[pd].a < Q[pq].a){
				update(D[pd].b,-1);
				pd++;
			}

			ans[Q[pq].idx] = query(Q[pq].b) + Q[pq].b - Q[pq].a + 1;

			pq++;

		}

		for(int i=0;i<q;i++)
			printf("%I64d\n",ans[i]);


	}