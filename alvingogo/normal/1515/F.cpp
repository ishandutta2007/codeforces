#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

vector<int> ss,bo2;
vector<vector<pair<int,int> > > e;
int x;
int find2(int x){
	return bo2[x]==x?x:bo2[x]=find2(bo2[x]);
}
vector<int> ans,ans2;
void dfs(int r,int f,int i){
	for(auto h:e[r]){
		if(h.fs!=f){
			dfs(h.fs,r,h.sc);
		}
	}
	if(r==0){
		return;
	}
	if(ss[r]>=x){
		ans.push_back(i);
		ss[f]+=ss[r];
		ss[f]-=x;
	}
	else{
		ans2.push_back(i);
	}
}
signed main(){
    AquA;
	int n,m;
	cin >> n >> m;
	cin >> x;
	bo2.resize(n);
	ss.resize(n);
	iota(bo2.begin(),bo2.end(),0);
	e.resize(n);
	long long cnt=0;
	for(int i=0;i<n;i++){
		cin >> ss[i];
		cnt+=ss[i];
	}
	if(cnt<1ll*(n-1)*x){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		if(find2(a)==find2(b)){
			continue;
		}
		int u=find2(a),w=find2(b);
		bo2[u]=w;
		e[a].push_back({b,i});
		e[b].push_back({a,i});
	}
	dfs(0,0,-1);
	reverse(ans2.begin(),ans2.end());
	for(auto h:ans){
		cout << h+1 << "\n";
	}
	for(auto h:ans2){
		cout << h+1 << "\n";
	}
    return 0;
}