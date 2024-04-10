#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int h[N],d[N],rt,mx[N],mx2[N]; 
long long ans;
basic_string<int>g[N];
void dfs1(int x,int y){
	mx[x]=h[x];
	for(int i:g[x])if(i^y){
		dfs1(i,x);
		mx[x]=max(mx[x],mx[i]);
	}
}
void dfs2(int x,int y){
	if(d[x]==1){
		ans+=h[x];
		if(mx2[x]<h[x])ans+=h[x]-mx2[x];
		return;
	}
	int w0=0,w1=0;
	for(int i:g[x])if(i^y){
		if(mx[i]>w0)w1=w0,w0=mx[i];
		else if(mx[i]>w1)w1=mx[i];
	}
	int w2=w0,w3=w1;
	if(h[x]>w0)w1=w0,w0=h[x];
	else if(h[x]>w1)w1=h[x];
	for(int i:g[x])if(i^y){
		if(mx[i]==w0)mx2[i]=w1;
		else mx2[i]=w0;
		mx2[i]=max(mx2[i],mx2[x]);
	}
	w0=w2,w1=w3;
	if(x!=rt){
		if(mx2[x]>w0)w1=w0,w0=mx2[x];
		else if(mx2[x]>w1)w1=mx2[x];
	}
	if(w0<h[x])ans+=h[x]-w0;
	if(w1<h[x])ans+=h[x]-w1;
	for(int i:g[x])if(i^y)dfs2(i,x);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;++i)cin>>h[i];
	for(i=1;i<n;++i){
		cin>>j>>k;
		g[j]+=k,g[k]+=j;
		++d[j],++d[k];
	}
	if(n==2){
		cout<<max(h[1],h[2])*2;
		return 0;
	}
	for(i=1;i<=n;++i)if(d[i]>1){rt=i;break;}
	dfs1(rt,0);
	dfs2(rt,0);
	cout<<ans;
	return 0;
}