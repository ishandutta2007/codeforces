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
#define maxn 300300

using namespace std;

int v[maxn];
int f[1001000];
int k;

int md(long long a){
	return (a%k+k)%k;
}

long long solve(int a,int b){
	debug("call %d %d\n",a,b);
	if(a >= b)
		return 0;
	if(a + 1 == b)
		return (min(v[a],v[b])%k == 0) ? 1 : 0;
	int mid = (a+b)/2;
	
	long long ret = solve(a,mid-1) + solve(mid+1,b);
	
	int p = mid;
	
	f[0] = 1;
	long long s = 0;
	int ma = v[mid];
	long long ac = 0;
	long long r = -1;
	debug("oi mid %d\n",mid);
	
	for(int i=mid;i<=b;i++){
		debug("i=%d ac %lld\n",i,ac);
		ma = max(ma,v[i]);
		s += v[i];
		while(p > a && v[p-1] <= ma){
			p--;
			debug("p=%d\n",p);
			ac += v[p];
			debug("ac %lld\n",ac);
			debug("add %d\n",(int)ac%k);
			f[ac%k]++;
		}
		r += f[md(ma-s)];
	}
	
	debug("r %lld\n",r);
	
	ac = 0;debug("ok");
	for(int i=mid-1;i>=p;i--){
		ac += v[i];
		f[ac%k]--;
	}
	
	
	ac = 0, ma = v[mid], s = 0, f[0] = 1, p = mid;
	
	for(int i=mid;i>=a;i--){
		ma = max(ma,v[i]);
		s += v[i];
		while(p < b && v[p+1] < ma){
			p++;
			ac += v[p];
			f[ac%k]++;
		
		}
		if(ma != v[mid]) r += f[md(ma-s)];
	}
	
	ac = 0;
	for(int i=mid+1;i<=p;i++){
		ac += v[i];
		f[ac%k]--;
	}
	
	debug("%d %d mid %d r %lld tot %lld\n",a,b,mid,r,ret+r);
	return ret+r;
	
}

main(){
	
	int n;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
		
	printf("%lld\n",solve(0,n-1));
	
}

//9 9 18 33 !48 141 129 84 81 48
//3 3 0  3   0  3   3   0  3  0