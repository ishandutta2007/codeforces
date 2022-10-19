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

long long ii[22];
long long ee[22];

int v[2001000];

map<int,int> mp;
int cc[2001000];

int cur = 0;
int T[2001000];
int tt[2001000];

long long ig[22];

void update(int idx){
	idx++;
	while(idx < 2001000){
		if(tt[idx] != cur)
			tt[idx] = cur, T[idx] = 0;
		T[idx]++;
		idx += idx&-idx;}
}

int query(int idx){
	idx++;
	int ret = 0;
	while(idx){
		if(tt[idx] != cur)
			tt[idx] = cur, T[idx] = 0;
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

long long merge_sort(int *p, int tam,int k){

	debug("tam = %d\n",tam);

	if(tam == 1)
		return 0;

	long long inv = 0;

	inv += merge_sort(p,tam/2,k-1);
	inv += merge_sort(p+tam/2,tam/2,k-1);

	int *vv = (int*) malloc(tam * sizeof(int));

	int t = 0;

	int pa=0, pb=tam/2;

	int sz = 0;

	while(pa < tam/2 && pb < tam){

		if(*(p+pa) < *(p+pb)){
			vv[sz++] = *(p+pa);
			pa++;
			inv += t;
		}
		else if(*(p+pa) > *(p+pb)){
			vv[sz++] = *(p+pb);
			pb++;
			t++;
		}
		else {
			int t0  = *(p+pa);
			while(pa < tam/2 && *(p+pa) == t0)
				vv[sz++] = *(p+pa), pa++, inv += t;
			while(pb < tam && *(p+pb) == t0)
				vv[sz++] = *(p+pb), pb++, t++;

			}

		}

	

	while(pa < tam/2)
		vv[sz++] = *(p+pa),
		pa++,
		inv += t;

	while(pb < tam)
		vv[sz++] = *(p+pb),
		pb++;

	for(int i=0;i<tam;i++)
		p[i] = vv[i];

	debug("ok");

	ii[k] += inv;

	int pp = 0;

	while(pp < tam){

		int p0 = pp;
		long long y = 0;

		while(pp < tam && p[pp] == p[p0])
			y++, pp++;

		ig[k] += (y*y-y)/2;

	}

	debug("ret ok\n");
	free(vv);
	return inv;
}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<(1<<n);i++)
			scanf("%d",v+i),
			cc[i] = v[i];

		sort(cc,cc+(1<<n));

	
		mp[cc[0]] = 0;
		for(int i=1;i<(1<<n);i++)
			if(cc[i] != cc[i-1])
				mp[cc[i]] = 1 + mp[cc[i-1]];

		for(int i=0;i<(1<<n);i++)
			v[i] = mp[v[i]];

		merge_sort(v,1<<n,n);
		
		/*for(int i=0;i<=n;i++){

			int count = (1<<i);
			for(int j=(1<<n)-1;j>=0;j--){

				
				ii[i] += query(v[j]-1);

				ig[i] += query(v[j]) - query(v[j]-1);
				
				update(v[j]);

				count--;
				if(count == 0){
					count = (1<<i);
					cur++;
				}
				
				}

			}*/

		for(int i=0;i<=n;i++)
			debug("ig[%d] = %I64d\n",i,ig[i]);

		for(int i=0;i<n;i++)
			ee[i] = ee[n] + ii[n] - ii[i];

		for(int i=0;i<=n;i++)
			debug("ii[%d] = %I64d\n",i,ii[i]);

		int q;
		scanf("%d",&q);

		while(q--){

			int k;
			scanf("%d",&k);

			long long t = (1<<k);

			ii[k] = (1<<(n-k)) * (t*t-t)/2 - ii[k] - ig[k];

			for(int i=k+1;i<=n;i++)

				ii[i] = ii[k] + ee[k] - ee[i];

			for(int i=0;i<k;i++){

				t = (1<<i);

				ii[i] = (1<<(n-i)) * (t*t-t)/2 - ii[i] - ig[i];
				ee[i] = ii[k] + ee[k] - ii[i];
				
				}

			printf("%I64d\n",ee[n]+ii[n]);

		}


	}