#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3,P=1e9+7;
char s[N];
int u[N],v[N],sa[N],t[N],h[N],f[N],id[N],wa[N],wb[N],wc[N],p[N];
using ll=long long;
ll ans[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void add(int l,int r,ll w){ans[l]-=w,ans[r]+=w;}
void mg(int x,int y,int z){
	add(z,p[x],wa[x]*1ll*wb[x]*wc[x]);
	add(z,p[y],wa[y]*1ll*wb[y]*wc[y]);
	f[x]=y,p[y]=z,wa[y]+=wa[x],wb[y]+=wb[x],wc[y]+=wc[x];
}
int main(){
	int*rk=u,*b=v,la,lb,n,i,j,k=0,m=131,x,y;
	scanf("%s",s+1),la=strlen(s+1),s[la+1]='A';
	scanf("%s",s+la+2),lb=strlen(s+1),s[lb+1]='B';
	scanf("%s",s+lb+2),n=strlen(s+1);
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
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(0,k-1);s[i+k]==s[j+k];++k);
	for(i=1;i<=n;++i){
		f[i]=id[i]=i,p[i]=n-i+1;
		if(i<=la)wa[i]=1;
		if(i>la+1&&i<=lb)wb[i]=1;
		if(i>lb+1)wc[i]=1;
	}
	sort(id+2,id+n+1,[](int x,int y){return h[x]>h[y];});
	for(i=2;i<=n;++i)mg(gf(sa[id[i]-1]),gf(sa[id[i]]),h[id[i]]);
	i=gf(1),add(0,p[i],wa[i]*1ll*wb[i]*wc[i]);
	for(i=n;i;--i)ans[i]+=ans[i+1];
	for(i=1,j=min(la,min(lb-la-1,n-lb-1));i<=j;++i)printf("%lld ",(ans[i]%P+P)%P);
	return 0;
}