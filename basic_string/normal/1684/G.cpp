#include<bits/stdc++.h>
using namespace std;
/*enum{N=200009};
int a[N];*/
enum{N=1009};
int a[N],p[N];
bool v[N];
basic_string<int>g[N];
bool dfs(int x){
	for(int i:g[x]){
		if(!v[i]){
			v[i]=1;
			if(!p[i]||dfs(p[i])){p[i]=x;return 1;}
		}
	}
	return 0;
}
vector<pair<int,int>>ans;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i){
		if(a[i]*3ll>m){
			for(j=1;j<=n;++j){
				if(a[j]<a[i]&&a[i]%a[j]==0){
					if(a[i]*2ll+a[j]<=m){
						g[i]+=j;
					}
				}
			}memset(v,0,sizeof v);
			if(!dfs(i)){cout<<-1<<'\n';return 0;}
		}
	}
	for(i=1;i<=n;++i)if(p[i]){
		ans.push_back({a[p[i]]*2+a[i],a[p[i]]+a[i]});
	}else if(a[i]*3ll<=m)ans.push_back({a[i]*3,a[i]*2});
	cout<<ans.size()<<'\n';
	for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	/*int a,b;
	cin>>a>>b;
	get(a,b);*/
/*	int T,n,m,i,j,k,l;
	for(cin>>T;T--;){
		
	}*/
}/*
a*3%a*2=a
a*2%a=0
(a*2+1)%(a+1)=a
(a+1)%a=1
(a*2+k)%(a+k)=a 
(a+k)%a=k
a%k=0
0<k<a*/