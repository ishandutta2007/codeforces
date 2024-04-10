#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int x[N],y[N],f[N];
bool b[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,w;
	vector<int>v;
	for(cin>>T;T--;){
		cin>>n>>m;w=0;v={};
		for(i=1;i<=n;++i)f[i]=i;
		for(i=1;i<=m;++i){
			cin>>x[i]>>y[i];b[i]=0;
			if(gf(x[i])==gf(y[i])){
				b[i]=1;w=i;
				v.push_back(x[i]),v.push_back(y[i]);
			}else f[gf(x[i])]=gf(y[i]);
		}
		sort(begin(v),end(v));
		v.resize(unique(begin(v),end(v))-begin(v));
		if(m-n==2&&v.size()==3){
			for(i=1;i<=n;++i)f[i]=i;
			f[gf(x[w])]=gf(y[w]);
			for(i=1;i<=m;++i)if(!b[i]){
				if(gf(x[i])==gf(y[i]))b[i]=1;
				else f[gf(x[i])]=gf(y[i]);
			}b[w]=0;
		}
		for(i=1;i<=m;++i)cout<<b[i];cout<<'\n';
	}
}