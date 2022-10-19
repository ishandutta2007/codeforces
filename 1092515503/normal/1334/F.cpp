#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m,a[500100],b[500100],p[500100],inv[500100],d[500100];
bool che(){
	int pos=1;
	for(int i=1;i<=n;i++)if(a[i]==b[pos]&&pos<=m)pos++;
	return pos>m;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]),inv[b[i]]=i,d[i]=INF;
	inv[n+1]=m+1;
	for(int i=n;i;i--)if(!inv[i])inv[i]=inv[i+1];
	if(!che()){puts("NO");return 0;}
	puts("YES");
	for(int i=1,id;i<=n;i++){
		id=inv[a[i]];
		if(id<=m)d[id]+=min(p[i],0ll);
		if(id<=m&&b[id]==a[i]&&d[id]>0){
			if(id<m)d[id+1]+=d[id];
			d[id]=0;
		}
		d[0]+=p[i];
		if(id<=m)d[id]-=p[i];
		if(id<=m&&d[id]>=(INF>>1))d[id]=INF;
		if(id<m&&d[id+1]>=(INF>>1))d[id+1]=INF;
	}
	printf("%lld\n",accumulate(d,d+m+1,0ll));
	return 0;
}