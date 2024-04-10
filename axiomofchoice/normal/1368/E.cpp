#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
vector<int> a[N],ans;
int w[N];
void Solve(){
	int n,m; cin>>n>>m;
	repeat(i,1,n+1)a[i].clear(),w[i]=0; ans.clear();
	while(m--){
		int x,y; cin>>x>>y;
		a[y].push_back(x);
	}
	repeat(x,1,n+1){
		for(auto p:a[x])
		if(w[p]!=2)
			w[x]=max(w[x],w[p]+1);
		if(w[x]==2)ans.push_back(x);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<' '; cout<<endl;
}
signed main(){
	int T=1; cin>>T;
	while(T--)Solve();
	return 0;
}