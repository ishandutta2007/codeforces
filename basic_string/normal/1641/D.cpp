#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline","-funroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
enum{N=100009};
bitset<N>b,ans,tmp[9999];
map<int,int>mp;
basic_string<int>g[N*5];
struct T{
	int a[5],w;
}t[N];
int p[N*5];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,id=0,i,j,ct=0,nowans=2e9+9;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		set<int>s;
		for(j=0;j<m;++j)cin>>t[i].a[j],s.insert(t[i].a[j]);
		cin>>t[i].w;
		if(s.size()<m){
			--n,--i;
			continue;
		}
	}
	sort(t+1,t+n+1,[](T a,T b){return a.w<b.w;});
	for(i=1;i<=n;++i){
		for(j=0;j<m;++j){
			int k=t[i].a[j];
			if(!mp[k])mp[k]=++id;
			t[i].a[j]=mp[k];
			g[t[i].a[j]]+=i;
		}
	}
	for(i=1;i<=id;++i)if(g[i].size()>100){
		p[i]=++ct;
		for(int o:g[i])tmp[ct][o]=1;
	}
	for(i=1;i<n;++i){
		if(t[i].w+t[i+1].w>nowans)break;
		ans.reset();
		for(j=0;j<m;++j){
			int k=t[i].a[j];
			if(p[k]){
				ans|=tmp[p[k]];
			}else{
				for(int o:g[k])b[o]=1;
				ans|=b;
				for(int o:g[k])b[o]=0;
			}
			
		}
		ans.flip();
			int o=ans._Find_next(i);
			if(o<=n){
				int x=t[i].w+t[o].w;
				if(x<nowans)nowans=x;
			}
	}
	if(nowans>(2e9+3))cout<<-1;
	else cout<<nowans;
	return 0;
}