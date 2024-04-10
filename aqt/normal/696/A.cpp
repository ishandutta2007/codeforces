#include <bits/stdc++.h>
using namespace std;

#define int long long

//cost of edge to parent
map<int,int> mp;

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;cin>>q;
	while(q--){
		//cerr<<"q\n";
		int op;cin>>op;
		if(op==1){
			int v,u,w;cin>>v>>u>>w;
			//assert u>v
			if(u<v)swap(u,v);
			//move up u to v level
			while(__builtin_clzll(u)!=__builtin_clzll(v)){
				//cerr<<u<<" "<<v<<"\n";
				mp[u]+=w;
				u>>=1;
			}
			while(u!=v){
				mp[u]+=w;
				mp[v]+=w;
				u>>=1;
				v>>=1;
			}
		}
		else {
			int v,u;cin>>v>>u;
			int ans=0;
			//assert u<v
			if(u<v)swap(u,v);
			//move up u to v level
			while(__builtin_clzll(u)!=__builtin_clzll(v)){
				ans+=mp[u];
				u>>=1;
			}
			while(u!=v){
				ans+=mp[u];
				ans+=mp[v];
				u>>=1;
				v>>=1;
			}
			cout<<ans<<"\n";
		}
	}
}