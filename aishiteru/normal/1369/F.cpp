#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
typedef long long ll;
ll a[N],b[N];
int n,f[N],g[N];
ll cal(const ll s,register ll e){
	if(s*2>e||s+1>e) return 1;
	e>>=1;
	if(e&1 || 2*s>e) return (e-s)&1;
	return cal(s,e>>1);
}
int main(){
	scanf("%d",&n);it i;ll x,y;
	for(i=0;i<n;++i) scanf("%lld%lld",&x,&y),a[i]=cal(x,y<<1),b[i]=cal(x,y);
	g[0]=1,f[0]=0;
	for(i=0;i<n;++i) f[i+1]=a[i]?g[i]:f[i],g[i+1]=b[i]?g[i]:f[i];
	printf("%d %d",f[n],g[n]);
	return 0;
}