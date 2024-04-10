#include<bits/stdc++.h>
using namespace std;
int T,n,a[300001],p[300001],g[300001],h[300001];
int main(){
	cin>>T;
	while(T--){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[i]=g[i]=h[i]=0;
	for(int i=1;i<=n;i++){
		g[a[i]]=max(g[a[i]],i-p[a[i]]);
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++)g[a[i]]=max(g[a[i]],n+1-p[a[i]]),h[i]=999999;
	for(int i=1;i<=n;i++)h[g[i]]=min(h[g[i]],i),h[g[i]]=min(h[g[i]],i);
	for(int i=2;i<=n;i++)h[i]=min(h[i],h[i-1]);
	for(int i=1;i<=n;i++)if(h[i]!=999999)printf("%d ",h[i]);else printf("-1 ");printf("\n");
}
	return 0;
}