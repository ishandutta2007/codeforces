#include<bits/stdc++.h>
using namespace std;
const int N=6e5+3;
char str[N];
int s[N],c[N],u[N],v[N],h[N],sa[N],t[N],f[N],id[N],len[N];
long long w[N],ans;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y,int z){
	if(len[x]>z)ans=max(ans,w[x]*len[x]);
	if(len[y]>z)ans=max(ans,w[y]*len[y]);
	f[x]=y,w[y]+=w[x],len[y]=z;
}
int main(){
	int*rk=u,*b=v,n=0,o,i,j,k=0,m,x,y;
	scanf("%d",&o),m=o+999;
	for(i=1;i<=o;++i){
		scanf("%s",str+1),j=strlen(str+1);
		for(x=1;x<=j;++x)s[++n]=str[x],w[n]=i,len[n]=j-x+1;
		s[++n]=i+199;
	}
	for(i=1;i<=o;++i)scanf("%d",c+i);
	for(i=1;i<=n;++i)w[i]=c[w[i]],++t[s[i]];
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,memset(t,0,m*4+4),k=0;j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(k-1,0);s[j+k]==s[i+k];++k);
	for(i=1;i<=n;++i)f[i]=id[i]=i;
	sort(id+2,id+n+1,[](int x,int y){return h[x]>h[y];});
	for(i=2;i<=n;++i)mg(gf(sa[id[i]-1]),gf(sa[id[i]]),h[id[i]]);
	if(i=gf(1),len[i])ans=max(ans,w[i]);
	cout<<ans;
	return 0;
}