#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
char s[N];
int tu[N],tv[N],sa[N],*rk=tu,*bb=tv,t[N],st[23][N],lg[N],stk[N],sz[N],n,tp;
long long ans,w;
basic_string<int>a,b;
int lcp(int x,int y){
	if(x==y)return n-sa[x]+1;
	if(x>y)swap(x,y);
	int i=lg[y-x];
	return min(st[i][x+1],st[i][y-(1<<i)+1]);
}
void ins(int x){
	while(tp>1&&lcp(stk[tp-1],x)==lcp(stk[tp],x))w-=sz[tp-1]*1ll*lcp(stk[tp-1],stk[tp]),sz[tp-1]+=sz[tp],--tp;
	if(tp)w+=sz[tp]*1ll*lcp(stk[tp],x);
	stk[++tp]=x,sz[tp]=1;
}
void get(int x){
	while(tp>1&&lcp(stk[tp-1],x)==lcp(stk[tp],x))w-=sz[tp-1]*1ll*lcp(stk[tp-1],stk[tp]),sz[tp-1]+=sz[tp],--tp;
	ans+=w;
	if(tp)ans+=sz[tp]*1ll*lcp(stk[tp],x);
}
int main(){
	int q,i,m=131,k=0,j,x,y,ta,tb;
	for(scanf("%d%d%s",&n,&q,s+1),i=1,lg[0]=-1;i<=n;++i)++t[s[i]],lg[i]=lg[i>>1]+1;
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,k=0,memset(t,0,m*4+4);j<=n;++j)bb[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)bb[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[bb[j]]]--]=bb[j];
		for(j=1,k=y=0,swap(rk,bb);j<=n;++j,y=x)x=sa[j],rk[x]=bb[x]==bb[y]&&bb[x+i]==bb[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;st[0][rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(k-1,0);s[i+k]==s[j+k];++k);
	for(i=0;i<22;++i)for(j=2,k=n-(1<<i+1)+2;j<k;++j)st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
	while(q--){
		scanf("%d%d",&ta,&tb),a=b={};
		for(i=1;i<=ta;++i)scanf("%d",&j),a+=rk[j];
		for(i=1;i<=tb;++i)scanf("%d",&j),b+=rk[j];
		sort(begin(a),end(a)),a.resize(unique(begin(a),end(a))-begin(a));
		sort(begin(b),end(b)),b.resize(unique(begin(b),end(b))-begin(b));
		i=0,ta=a.size(),ans=w=tp=0;
		for(int o:b){
			while(i<ta&&a[i]<=o)ins(a[i++]);
			get(o);
		}
		w=tp=i=0,reverse(begin(a),end(a)),reverse(begin(b),end(b));
		for(int o:b){
			while(i<ta&&a[i]>o)ins(a[i++]);
			get(o);
		}
		printf("%lld\n",ans);
	}
	return 0;
}