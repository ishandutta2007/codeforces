#include<bits/stdc++.h>
using namespace std;
enum{N=200009,M=N*4};
map<int,int>pr;
int a[N],b[N],s[M],t[M],u,v,w,x,n,al=1,ar,s1[N],s2[N],t1,t2;
void add(int k,int l,int r){
	if(u<=l&&r<=v){t[k]+=w,s[k]+=w;return;}
	int m=l+r>>1;
	if(u<=m)add(k*2,l,m);
	if(m<v)add(k*2+1,m+1,r);
	s[k]=min(s[k*2],s[k*2+1])+t[k];
}
void qry(int k,int l,int r,int w){
	if(l==r){
		if(s[k]<=w&&ar-al<x-l)al=l,ar=x;
		return;
	}
	int m=l+r>>1;
	if(w-=t[k],s[k*2]<=w)qry(k*2,l,m,w);else qry(k*2+1,m+1,r,w);
}
void ad(int l,int r,int x){u=l,v=r,w=x,add(1,1,n);}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int k,d,i,o;
	for(cin>>n>>k>>d,i=1;i<=n;++i)cin>>a[i];
	if(!d){
		for(i=k=1;i<=n;++i)if(i==n||a[i]!=a[i+1]){
			if(ar-al<i-k)al=k,ar=i;
			k=i+1;
		}
		return cout<<al<<' '<<ar,0;
	}
	for(ad(1,n,M),x=o=1;x<=n;++x){
		if(b[x]=a[x]/d,x>1&&(a[x]-a[x-1])%d)ad(o,x-1,M),o=x;
		if(pr[a[x]]>=o)ad(o,pr[a[x]],M),o=pr[a[x]]+1;
		for(;t1&&b[x]>b[s1[t1]];--t1)ad(s1[t1-1]+1,s1[t1],b[x]-b[s1[t1]]);
		for(;t2&&b[x]<b[s2[t2]];--t2)ad(s2[t2-1]+1,s2[t2],b[s2[t2]]-b[x]);
		pr[a[x]]=x,s1[++t1]=s2[++t2]=x,ad(x,x,x-M),qry(1,1,n,k+x);
	}
	cout<<al<<' '<<ar;
	return 0;
}