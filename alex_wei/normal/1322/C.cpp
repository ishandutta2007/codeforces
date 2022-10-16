#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
set <int> e[N];
map <set<int>,int> mp;
int t,m,n;
ll c[N],c2[N];
int main(){
	cin>>t;
	while(t--){
		mp.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&c[i]),c2[i]=0,e[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[v].insert(u);
		}
		for(int i=1;i<=n;i++){
			if(e[i].size()==0)continue;
			if(mp.find(e[i])==mp.end()){
				mp[e[i]]=i;
				c2[i]+=c[i];
			}
			else c2[mp[e[i]]]+=c[i];
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans=__gcd(ans,c2[i]);
		printf("%lld\n",ans);
	}
    return 0;
}