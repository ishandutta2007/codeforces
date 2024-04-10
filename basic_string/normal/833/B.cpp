#include<bits/stdc++.h>
using namespace std;
enum{N=35009};
int n,k,c[N],a[N],F[N],G[N],*f=F,*g=G,u=1,v,o;
void get(int l,int r){
	while(v<r)o+=!(c[a[++v]]++);
	while(u>l)o+=!(c[a[--u]]++);
	while(v>r)o-=!(--c[a[v--]]);
	while(u<l)o-=!(--c[a[u++]]);
}
void wk(int l,int r,int pl,int pr){
	if(l>r)return;
	int m=(l+r)/2,i,pm=0,w=0,u;
	for(i=pl;i<=pr&&i<m;++i)if(get(i+1,m),(u=g[i]+o)>w)w=u,pm=i;
	f[m]=w,wk(l,m-1,pl,pm),wk(m+1,r,pm,pr);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=k;++i)swap(f,g),wk(1,n,0,n-1);
	cout<<f[n];
}