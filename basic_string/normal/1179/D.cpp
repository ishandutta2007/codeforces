#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
using ll=long long;
ll ans=1e18,p[N],y[N];
basic_string<int>g[N];
int s[N],n,q[N],a[N];
void dfs(int x,int f){
	s[x]=1;
	for(int i:g[x])if(i!=f)dfs(i,x),s[x]+=s[i];
	p[x]=s[x]*1ll*s[x];
	int m=0,i,j,k,t=1;
	for(int i:g[x])if(i!=f)p[x]=min(p[x],p[i]+(s[x]-s[i])*1ll*(s[x]-s[i])),a[++m]=i,ans=min(ans,p[i]+(n-s[i])*1ll*(n-s[i]));
	sort(a+1,a+m+1,[](int x,int y){return s[x]<s[y];}),q[1]=i=a[1],y[i]=s[i]*(s[i]-2ll*n)+p[i];
	for(i=2;i<=m;++i){
		k=-2*s[j=a[i]];
		while(t>1&&y[q[t]]-y[q[t-1]]>k*1ll*(s[q[t]]-s[q[t-1]]))--t;
		k=q[t],ans=min(ans,(n-s[j]-s[k])*1ll*(n-s[j]-s[k])+p[j]+p[k]),y[j]=s[j]*(s[j]-2ll*n)+p[j];
		while(t>1&&(y[q[t]]-y[q[t-1]])*(s[j]-s[q[t]])>=(y[j]-y[q[t]])*(s[q[t]]-s[q[t-1]]))--t;
		q[++t]=j;
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	dfs(1,0),printf("%lld",(n*1ll*(2*n-1)-ans)/2);
	return 0;
}