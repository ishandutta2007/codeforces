#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int T,n,cnt,ans,res;
pair<int,int> p[300005];
set<pair<int,int> > s;
vector<int> v[300005],e[300005];
void dfs(int x){
	p[x].first=++cnt;
	for(int i=0;i<e[x].size();++i)dfs(e[x][i]);
	p[x].second=++cnt;
}
void sol(int x){
	bool in=0,ot=0;
	pair<int,int> OT;
	if(s.empty()){
		s.insert(p[x]);
		in=1;
		++res;
	}
	else{
		set<pair<int,int> >::iterator it=s.lower_bound(p[x]);
		if(it==s.end()||(it->first)>p[x].second){
			in=1;
			++res;
			if(it!=s.begin()){
				--it;
				if(it->second>p[x].first){
					ot=1;
					--res;
					OT=*it;
					s.erase(it);
				}
			}
			s.insert(p[x]);
		}
	}
	ans=max(ans,res);
	for(int i=0;i<v[x].size();++i)sol(v[x][i]);
	if(in)s.erase(p[x]),--res;
	if(ot)s.insert(OT),++res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		for(int i=1;i<=n;++i)v[i].clear(),e[i].clear();
		for(int i=2;i<=n;++i){
			int x;
			scanf("%d",&x);
			v[x].pb(i);
		}
		for(int i=2;i<=n;++i){
			int x;
			scanf("%d",&x);
			e[x].pb(i);
		}
		dfs(1);
		ans=1;
		sol(1);
		printf("%d\n",ans);
	}
    return 0;
}