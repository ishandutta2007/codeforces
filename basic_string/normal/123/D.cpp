#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int u[N],v[N],sa[N],*rk=u,*b=v,t[N],h[N],st[N],sz[N];
int main(){
	int i,j,k=0,m=131,n,x,y;
	long long ans;
	scanf("%s",s+1),n=strlen(s+1),ans=n*(n+1ll)/2;
	for(i=1;i<=n;++i)++t[s[i]];
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,k=0,memset(t,0,m*4+4);j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(k-1,0);s[i+k]==s[j+k];++k);
	for(i=2,k=1;i<=n+1;++i){
		while(st[k-1]>h[i])ans+=sz[k]*(sz[k]+1ll)/2*(st[k]-st[k-1]),sz[k-1]+=sz[k],--k;
		if(st[k]>=h[i])ans+=sz[k]*(sz[k]+1ll)/2*(st[k]-h[i]),++sz[k],st[k]=h[i];
		else st[++k]=h[i],sz[k]=1;
	}
	cout<<ans;
	return 0;
}