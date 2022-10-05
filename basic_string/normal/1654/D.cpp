#include<bits/stdc++.h>
using namespace std;
enum{N=200009,P=998244353};
int n,a[N];
struct O{
	int k,x,y;
};
vector<O>v[N];
vector<pair<int,int>>fc[N];
inline void wk(int w,int c){
	if(a[w]<c)a[w]=c;
}
void fcc(int x){
	int i=2,w=x,j;
	for(;i*i<=w;++i)if(w%i==0){
			j=0;
			do w/=i,++j;while(w%i==0);
			fc[x].push_back({i,j});
		}
		if(w>1)fc[x].push_back({w,1});
}
void dfs(int x,int y){
	for(auto o:v[x])if(o.k!=y){
		int i=2,w=o.x,j;
		for(auto u:fc[w]){
		if(a[u.first]<u.second)
			a[u.first]=u.second;
			a[u.first]-=u.second;
		}
		for(auto u:fc[o.y]){
			a[u.first]+=u.second;
		}
	/*	for(;i*i<=w;++i)if(w%i==0){
			j=0;
			do w/=i,++j;while(w%i==0);
			wk(i,j);
		}
		if(w>1)wk(w,1);*/
		dfs(o.k,x);
		for(auto u:fc[o.y]){
			a[u.first]-=u.second;
		}
		for(auto u:fc[o.x])a[u.first]+=u.second;
	}
}
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int ans;
void dfs2(int x,int y,int z){
	ans=(ans+z)%P;
	for(auto o:v[x])if(o.k!=y){
		dfs2(o.k,x,z*1ll*o.y%P*qp(o.x,P-2)%P);
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k,x,y,d,now;
	for(i=1;i<N;++i)fcc(i);
	for(cin>>T;T--;){
		
		cin>>n;ans=0;
		
		for(i=1;i<=n;++i)v[i]={},a[i]=0;
		for(i=1;i<n;++i){
			cin>>j>>k>>x>>y;
			d=__gcd(x,y);
			x/=d,y/=d;
			v[j].push_back({k,x,y});
			v[k].push_back({j,y,x});
			
		}
		dfs(1,0);
		now=1;
		for(i=1;i<=n;++i){
			for(j=1;j<=a[i];++j)now=now*1ll*i%P;
		}
		dfs2(1,0,now);
		cout<<(ans%P+P)%P<<'\n';
	}
}