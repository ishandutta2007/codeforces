#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int s[N],u[N],v[N],sa[N],t[N],*rk=u,*b=v,st[23][N],lg[N],ans[N],n;
unordered_map<int,int>mp;
int lcp(int x,int y){
	int i=lg[y-x];
	return min(st[i][x+1],st[i][y-(1<<i)+1]);
}
struct Q{
	int l,r,i;
	bool b;
}qq;
vector<Q>vc[N];
void ins(int x,int y){if(x<y)qq.b=0,vc[x].push_back(qq),qq.b=1,vc[y].push_back(qq);}
void add(int x){for(;x<=n;x+=x&-x)++t[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
int main(){
	int o,q,i,j,k=0,m=0,x,y,z,l,r;
	for(scanf("%d",&o),i=1;i<=o;++i)scanf("%d",s+i);
	for(i=1;i<o;++i){
		if(s[i]=s[i+1]-s[i],!mp[s[i]])mp[s[i]]=++m;
		if(!mp[-s[i]])mp[-s[i]]=++m;
		s[i+o]=mp[-s[i]],s[i]=mp[s[i]];
	}
	for(s[o]=++m,n=o*2-1,i=1,lg[0]=-1;i<=n;++i)++t[s[i]],lg[i]=lg[i>>1]+1;
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,k=0,memset(t,0,m*4+4);j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;st[0][rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(k-1,0);s[i+k]==s[j+k];++k);
	for(i=0;i<20;++i)for(j=2,k=n-(1<<i+1)+2;j<k;++j)st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
	for(scanf("%d",&q),i=1;i<=q;++i){
		if(scanf("%d%d",&x,&y),x==y){ans[i]=o-1;continue;}
		k=y-x,--y,z=rk[x];
		for(l=1,r=z-1;l<=r;)if(m=l+r>>1,lcp(m,z)<k)l=m+1;else r=m-1;
		for(j=l,l=z+1,r=n;l<=r;)if(m=l+r>>1,lcp(z,m)<k)r=m-1;else l=m+1;
		qq={j-1,r,i},ins(o,x-y+x-2+o),ins(o+y+1,n);
	}
	for(i=o,memset(t,0,n*4+4);i<=n;++i){
		add(rk[i]);
		for(auto o:vc[i])if(j=sum(o.r)-sum(o.l),o.b)ans[o.i]+=j;else ans[o.i]-=j;
	}
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}