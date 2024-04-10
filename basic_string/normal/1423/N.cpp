#include<bits/stdc++.h>
using namespace std;
enum{N=1000009};
int x[N],y[N],w[N],s[N];
bool v[N],b[N];
vector<pair<int,int>>g[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,j,k;
	for(i=1,cin>>n>>m;i<=m;++i)w[i]=1,cin>>j>>k,x[i]=j,y[i]=k,g[max(j,k)].emplace_back(min(j,k),i),++s[j],++s[k];
	for(i=1;i<=n;++i){
		for(auto o:g[i]){
			if(!v[o.first])v[o.first]=1,w[o.second]=0,--s[i];
			b[s[o.first]]=1;
		}
		for(auto o:g[i]){
			if(!b[s[i]])break;
			++s[i],v[o.first]=0,++w[o.second];
		}
		for(auto o:g[i])b[s[o.first]]=0;
	}
	for(i=1,j=0;i<=n;++i)if(v[i])++j;
	for(cout<<j<<'\n',i=1;i<=n;++i)if(v[i])cout<<i<<' ';
	for(i=1;i<=m;++i)cout<<'\n'<<x[i]<<' '<<y[i]<<' '<<w[i];
	return 0;
}