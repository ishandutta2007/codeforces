#include <iostream>
#include <iomanip>
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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

#define X second.first
#define Y second.second

using namespace std;

struct query {
	long long p,qnt,idx,ans;
	bool operator<(query comp)const {
		if(p != comp.p) return p < comp.p;
		return qnt < comp.qnt;
	}
}

Q[100100];

int v[100100];
long long resp[100100];

int st[100100];
int len;

long long psum[100100];

long long ret;
inline long long getsum(int a,int b){
	ret = psum[b];
	if(a) ret -= psum[a-1];
	debug("sum %d %d = %lld\n",a,b,ret);
	return ret;
}

main(){

		int n,q;
		scanf("%d",&n);

		for(int i=0;i<n;i++) scanf("%d",v+i), v[i] *= -1;

		psum[0] = v[0];
		for(int i=1;i<n;i++) psum[i] = psum[i-1] + v[i];

		scanf("%d",&q);

		for(int i=0;i<q;i++){
			int p,qnt;
			scanf("%d%d",&qnt,&p);
			p--;
			Q[i].p = p;
			Q[i].qnt = qnt;
			Q[i].idx = i;
		}

		sort(Q,Q+q);

		int ptr = 1;
		int len = 1;
		st[0] = 0;

		for(int i=0;i<q;i++){

			if(Q[i].p == 0){
				Q[i].ans = Q[i].qnt * v[0];
				continue;
			}

			while(ptr <= Q[i].p){
				if(v[ptr] < v[ptr-1]){ptr++;continue;}
				while(len && v[st[len-1]] <= v[ptr])len--;
				st[len++] = ptr;
				ptr++;
			}

			int i0 = i;

			int last = len-1;
			for(int j=i;Q[j].p == Q[i0].p;j++){

				long long ans = -1;
				if(Q[j].qnt <= Q[j].p + 1) ans = getsum(Q[j].p-Q[j].qnt+1,Q[j].p);
				debug("query %d\n",Q[j].idx);
				int qual;
				for(int k=last;k>=0;k--){
					//if(Q[j].qnt - Q[j].p + st[k] <= 0) break;
					debug("st[k] = %d\n",st[k]);
					long long cand = getsum(st[k]+1,Q[j].p) + (long long)v[st[k]] * (Q[j].qnt - Q[j].p + st[k]);
					//if(cand == 10) debug("p = %lld qnt = %lld st[k] = %d ",Q[j].p,Q[j].qnt,st[k]);
					if(cand >= ans){
						ans = cand;
						qual = k;
					}
				}
				Q[j].ans = ans;
				last = qual;
	
			}
								

		}

	for(int i=0;i<q;i++)
		resp[Q[i].idx] = Q[i].ans;
	for(int i=0;i<q;i++)
		printf("%I64d\n",-resp[i]);

}