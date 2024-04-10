#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300
#define mod 1000000007

typedef long long ll;
using namespace std;

int T[2][4*maxn];
int p2[maxn];

void update(int init,int fim,int p,int pos,int val){
	if(init > pos || fim < pos)
		return;
	if(init == fim){
		T[0][p] = T[1][p] = val;
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,pos,val);
	update(mid+1,fim,2*p+1,pos,val);
	T[0][p] = (T[0][2*p] + (ll) p2[mid-init+1] * T[0][2*p+1]) % mod;
	T[1][p] = (T[1][2*p+1] + (ll) p2[fim-mid] * T[1][2*p]) % mod;
}

pii get(int init,int fim,int p,int l,int r,int t){

	if(init > r || fim < l)
		return pii(0,0);
	if(init >= l && fim <= r)
		return pii(T[t][p],fim-init+1);
	int mid = (init+fim)/2;
	if(t == 0){
		pii u = get(init,mid,2*p,l,r,t);
		pii v = get(mid+1,fim,2*p+1,l,r,t);
		return pii((u.first + (ll) p2[u.second] * v.first) % mod, u.second+v.second);
	}
	else {
		pii u = get(mid+1,fim,2*p+1,l,r,t);
		pii v = get(init,mid,2*p,l,r,t);
		return pii((u.first + (ll) p2[u.second] * v.first) % mod, u.second+v.second);
	}
}

main(){

	int ans = 0;

	int n;
	scanf("%d",&n);

	p2[0] = 1;
	for(int i=1;i<=n;i++)
		p2[i] = (2*p2[i-1])%mod;

	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u), u--;
		update(0,n-1,1,u,1);
		int len = min(u,n-u-1);
		if(len == 0)
			continue;
		if(get(0,n-1,1,u+1,u+len,0) != get(0,n-1,1,u-len,u-1,1))
			ans = 1;
	}
	
	printf("%s\n",ans?"YES":"NO");

}