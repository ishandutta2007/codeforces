#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
using ll=long long;
ll F[N],G[N],*f=F,*g=G,w;
int a[N],u=1,v,c[N];
void get(int l,int r){
	while(v<r)w+=c[a[++v]]++;
	while(u>l)w+=c[a[--u]]++;
	while(v>r)w-=--c[a[v--]];
	while(u<l)w-=--c[a[u++]];
}
void wk(int l,int r,int pl,int pr){
	if(l>r)return;
	int i,m=(l+r)/2,pm=0;
	ll fm=1e18;
	for(i=pl;i<=pr&&i<m;++i)if(get(i+1,m),g[i]+w<fm)fm=g[i]+w,pm=i;
	f[m]=fm,wk(l,m-1,pl,pm),wk(m+1,r,pm,pr);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,i;
	cin>>n>>k,memset(f,9,N*8),f[0]=0;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=k;++i)swap(f,g),wk(i,n,i-1,n-1);
	cout<<f[n];
}