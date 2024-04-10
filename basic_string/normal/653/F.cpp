#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=N*2;
char s[N];
int u[N],v[N],sa[N],h[N],t[N],w[N],ps[N],r[N],f[N],id[N],p[N],st[N];
long long ans;
basic_string<int>bs[M];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int get(int x,int l){
	--x;
	int i=min(r[x]-1,x+l),j=w[x];
	return upper_bound(bs[j].begin(),bs[j].end(),i)-bs[j].begin()-ps[x];
}
void mg(int x,int y,int z){
	ans+=get(x,p[x])-get(x,z)+get(y,p[y])-get(y,z);
	f[x]=y,p[y]=z;
}
int main(){
	int*rk=u,*b=v,m=131,n,i,j,k=0,x,y,tp=0;
	scanf("%d%s",&n,s+1);
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
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(0,k-1);s[i+k]==s[j+k];++k);
	for(w[0]=N,i=1;i<=n;++i)w[i]=w[i-1]+(s[i]=='('?1:-1);
	for(i=0;i<=n;++i)bs[w[i]]+=i,ps[i]=bs[w[i]].size();
	for(i=n,st[++tp]=n+1;i>=0;--i){
		while(w[i]<=w[st[tp]])--tp;
		r[i]=st[tp],st[++tp]=i;
	}
	for(i=1;i<=n;++i)f[i]=id[i]=i,p[i]=n-i+1;
	sort(id+2,id+n+1,[](int x,int y){return h[x]>h[y];});
	for(i=2;i<=n;++i)mg(gf(sa[id[i]-1]),gf(sa[id[i]]),h[id[i]]);
	cout<<ans;
	return 0;
}