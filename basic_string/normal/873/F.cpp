#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
char s[N],o[N];
int sa[N],u[N],v[N],t[N],h[N],id[N],f[N],sz[N];
long long ans;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y,int w){
	f[x]=y,sz[y]+=sz[x],ans=max(ans,w*1ll*sz[y]);
}
int main(){
	int*rk=u,*b=v,n,i,j,k=0,m=131,x,y;
	scanf("%d%s%s",&n,s+1,o+1),reverse(s+1,s+n+1),reverse(o+1,o+n+1);
	for(i=1;i<=n;++i)++t[s[i]];
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,memset(t,0,m*4+4),k=0;j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(k-1,0);s[i+k]==s[j+k];++k);
	for(i=1;i<=n;++i)if(id[i]=f[i]=i,o[i]=='0')sz[i]=1,ans=max(ans,n-i+1ll);
	sort(id+2,id+n+1,[](int x,int y){return h[x]>h[y];});
	for(i=2;i<=n;++i)mg(gf(sa[id[i]]),gf(sa[id[i]-1]),h[id[i]]);
	cout<<ans;
	return 0;
}