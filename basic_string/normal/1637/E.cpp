#include<bits/stdc++.h>
using namespace std;
enum{N=300009,B=509};
basic_string<int>e[N],p[B],q;
int c[N],w[N];
map<int,int>mp;
bool f[N]; 
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,o,i,j,k;
	long long ans;
	for(cin>>T;T--;){
		cin>>n>>m;ans=0;o=0;mp={};
		memset(c,0,n*4+4);
		for(i=1;i<=n;++i){
			cin>>j;
			if(!mp[j])mp[j]=++o,w[o]=j;
			++c[mp[j]];
		}
		for(i=1;i<=o;++i)e[i]={};
		while(m--)cin>>i>>j,i=mp[i],j=mp[j],e[i]+=j,e[j]+=i;
		for(i=1;i<=o;++i)e[i]+=i;
		for(i=0;i<B;++i)p[i]={};q={};
		for(i=1;i<=o;++i)if(c[i]<B)p[c[i]]+=i;else q+=i;
		for(i=0;i<B;++i)
		sort(begin(p[i]),end(p[i]),[](int x,int y){return w[x]>w[y];});
		for(i=1;i<=o;++i){
			for(int k:e[i])f[k]=1;
			for(int k:q)if(!f[k])ans=max(ans,(w[i]+w[k])*1ll*(c[i]+c[k]));
			for(j=0;j<B;++j)
			for(int k:p[j])if(!f[k]){
				ans=max(ans,(w[i]+w[k])*1ll*(c[i]+c[k]));
				break;
			}
			
			for(int k:e[i])f[k]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}