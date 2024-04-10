#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
inline int read(){
	int x=0;
	char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return x;
}
ll T,h[N],t,n,mi,ma;
struct node{
	ll v,c,w;
}e[N<<1];
void add(ll u,ll v,ll w){
	mi+=w;
	e[++T]=(node){v,h[u],w};
	h[u]=T;
	e[++T]=(node){u,h[v],w}; 
	h[v]=T;
}
ll dfs(ll id,ll f){
	ll sz=1;
	for(ll i=h[id];i;i=e[i].c){
		ll to=e[i].v;
		if(e[i].v==f)continue;
		ll res=dfs(to,id);
		ma+=e[i].w*min(res,n-res);
		if(res%2==0)mi-=e[i].w;
		sz+=res;
	}
	return sz;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		n*=2;
		T=mi=ma=0;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1;i<n;i++){ll u=read(),v=read(),w=read();add(u,v,w);}
		dfs(1,0);
		cout<<mi<<" "<<ma<<endl;
	}
	return 0;
}