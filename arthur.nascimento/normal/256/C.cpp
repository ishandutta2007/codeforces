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

int T[4001000];
int qnt[1001000];

void update(int idx,int val){
	idx++;
	while(idx < 4001000){
		T[idx] += val;
		idx += idx&-idx;
	}
}

void add(int x){
	if(++qnt[x] == 1)
		update(x,1);
}

void dec(int x){
	if(--qnt[x] == 0)
		update(x,-1);
}

int search(){

	int ret = 0;

	for(int i=21;i>=0;i--)
		if(T[ret+(1<<i)] == (1<<i))
			ret += (1<<i);

	return ret;

}

int nim[1001000];

long long v [100100]; 

main(){

		int n;
		scanf("%d",&n);

		int ans = 0;

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i);

		sort(v,v+n);

		long long pa=1, pb=0;
		long long t = 2;
		int p = 0;

		while(v[p] == 1)
			p++;

		while(t <= 1001000 && p < n){

			while((pb+1)*(pb+1) <= t)
				add(nim[pb+1]),
				pb++;

			while(pa*pa*pa*pa < t)
				dec(nim[pa]),
				pa++;

			nim[t] = search();
			debug("nim[%I64d] = %d pa = %I64d pb = %I64d\n",t,nim[t],pa,pb);

			while(v[p] == t && p < n)
				ans ^= nim[t],
				p++;

			t++;

			}

		while(p < n){

			t = v[p];

			while((pb+1)*(pb+1) <= t)
				add(nim[pb+1]),
				pb++;

			while(pa*pa*pa*pa < t)
				dec(nim[pa]),
				pa++;

			while(v[p] == t && p < n)
				ans ^= search(),
				p++;

			}

		printf("%s\n",ans ? "Furlo" : "Rublo");

}