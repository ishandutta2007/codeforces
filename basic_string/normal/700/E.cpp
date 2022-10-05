#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=N*4;
char s[N];
int u,v,n,f,o;
namespace SA{
int sa[N],tu[N],tv[N],t[N],*rk=tu,*b=tv,st[21][N],lg[N];
void bd(){
	int i,j,k=0,m=131,x,y;
	for(i=1,lg[0]=-1;i<=n;++i)++t[s[i]],lg[i]=lg[i>>1]+1;
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,k=0,memset(t,0,m*4+4);j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;st[0][x]=k,++i)if((x=rk[i])>1)for(j=sa[x-1],k=max(k-1,0);s[i+k]==s[j+k];++k);
	for(i=0;i<20;++i)for(j=2,k=n-(1<<i+1)+2;j<k;++j)st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
}
int lcp(int x,int y){
	int i=lg[y-x];
	return min(st[i][x+1],st[i][y-(1<<i)+1]);
}
void get(int x,int o){
	int l=1,m;
	for(x=rk[x],v=x-1;l<=v;)if(m=l+v>>1,lcp(m,x)<o)l=m+1;else v=m-1;
	for(u=l,l=x+1,v=n;l<=v;)if(m=l+v>>1,lcp(x,m)<o)v=m-1;else l=m+1;
}
}
namespace T1{
int tf[M],to[M];
void upd(int k,int l,int r){
	if(u<=l&&r<=v){if(tf[k]<f)tf[k]=f,to[k]=o;return;}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void qry(int k,int l,int r){
	if(f<tf[k])f=tf[k],o=to[k];
	if(l==r)return;
	int m=l+r>>1;
	u>m?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
}
namespace T2{
int t[M];
void upd(int k,int l,int r){
	if(l==r){t[k]=v;return;}
	int m=l+r>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),t[k]=min(t[k*2],t[k*2+1]);
}
int qry(int k,int l,int r){
	if(u<=l&&r<=v)return t[k];
	int m=l+r>>1,w=1e9;
	if(u<=m)w=qry(k*2,l,m);
	if(m<v)w=min(w,qry(k*2+1,m+1,r));
	return w;
}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,w=0;
	cin>>n>>(s+1),SA::bd(),memset(T2::t,9,M*4);
	for(i=n;i;--i){
		if(f=0,u=SA::rk[i],T1::qry(1,1,n),f)SA::get(i,o),++f,o+=T2::qry(1,1,n)-i;else f=o=1;
		w=max(w,f),SA::get(i,o),T1::upd(1,1,n),u=SA::rk[v=i],T2::upd(1,1,n);
	}
	cout<<w;
	return 0;
}