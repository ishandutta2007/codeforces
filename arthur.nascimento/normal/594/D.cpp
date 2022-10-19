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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

using namespace std;

int sieve[1001000];

int v[maxn];

struct _query {
	int a,b,idx;
	bool operator<(_query comp)const{
		return b < comp.b;
	}
}

Q[maxn];

int ans[maxn];

long long exp(long long a,int b){
	if(b == 0) return 1;
	long long k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2) k = (k*a)%mod;
	return k;
}

long long T[4*maxn];

void update(int init,int fim,int p,int pos,int val){
	if(pos > fim || pos < init) return;
	if(init == fim){
		T[p] = (T[p]*val) % mod;
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,pos,val);
	update(mid+1,fim,2*p+1,pos,val);
	T[p] = (T[2*p]*T[2*p+1])%mod;
}

long long query(int init,int fim,int p,int l,int r){
	if(l > fim || r < init) return 1;
	if(init >= l && fim <= r) return T[p];
	int mid = (init+fim)/2;
	long long ret =  (query(init,mid,2*p,l,r)*query(mid+1,fim,2*p+1,l,r))%mod;
		return ret;
}

void build(int init,int fim,int p){
	if(init == fim){
		T[p] = 1;
		return;
	}
	int mid = (init+fim)/2;
	build(init,mid,2*p);
	build(mid+1,fim,2*p+1);
	T[p] = 1;
}

int last[1001000];

int inv(int p){
	return exp(p,mod-2);
}

long long pp[maxn];

long long get(int a,int b){
	long long ret = pp[b];
	if(a) ret = (ret*inv(pp[a-1]))%mod;
	return ret;
}

long long mul(long long a,long long b){
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}

long long p1p[1001000];
long long pp1[1001000];

long long tira(int p){
	if(pp1[p]) return pp1[p];
	return pp1[p] = mul(p,inv(p-1));
}

long long bota(int p){
	if(p1p[p]) return p1p[p];
	return p1p[p] = mul(p-1,inv(p));
}

main(){

		for(int i=2;i<1001000;i++) if(!sieve[i]){
			for(int j=i;j<1001000;j+=i)
				sieve[j] = i;
		}

		int n,q;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		pp[0] = v[0];
		for(int i=1;i<n;i++)
			pp[i] = (pp[i-1]*v[i])%mod;

		scanf("%d",&q);

		for(int i=0;i<q;i++)
			scanf("%d%d",&Q[i].a,&Q[i].b), Q[i].a--, Q[i].b--, Q[i].idx = i;

		sort(Q,Q+q);

		build(0,n-1,1);
		memset(last,-1,sizeof(last));

		int pos = 0;
		for(int i=0;i<q;i++){
			while(pos < n && pos <= Q[i].b){
				//debug("add %d\n",pos);
				while(v[pos] != 1){
					int p = sieve[v[pos]];
					//debug("+p %d\n",p);
					v[pos] /= p;
					if(last[p] != -1){
						//debug("tira %d de %d\n",p,last[p]);
						update(0,n-1,1,last[p],tira(p));
					}
					last[p] = pos;
					update(0,n-1,1,pos,bota(p));
				}
				pos++;
			}
			long long u = get(Q[i].a,Q[i].b);
			u = (u*query(0,n-1,1,Q[i].a,Q[i].b)) % mod;
			ans[Q[i].idx] = u;
		}

		for(int i=0;i<q;i++)
			printf("%d\n",ans[i]);

}