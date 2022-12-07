#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
string days[7]={
"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int n,m,k;
int h[200005],ok[200005][7],it[200005],hav[200005],len[200005],ed[200005],vis[200005];
V<int> v[200005];
priority_queue<int,V<int>,greater<int> > q[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	FOR(i,1,n){
		int cnt;cin>>cnt;
		FOR(j,1,cnt){
			string s;
			cin>>s;
			rep(k,0,7)if(s==days[k]){
				ok[i][k]=1;break;
			}
		}
	}
	FOR(i,1,m)cin>>h[i];
	int T=0,pos=1;
	set<int> s;
	FOR(i,1,k){
		it[i]=1;cin>>len[i];
		v[i].resize(len[i]+1);
		FOR(j,1,len[i]){
			cin>>v[i][j];
		}
		q[v[i][1]].emplace(i);
	}
	FOR(i,1,n)if(!q[i].empty())s.emplace(i),vis[i]=1;
	while(1){
		if(pos<=m&&h[pos]==T+1){
			T++;pos++;continue;
		}
		V<int> ins; 
		for(auto u:s)if(!q[u].empty())if(ok[u][T%7]){
			int hav=q[u].top();q[u].pop();
			if(it[hav]==len[hav]){
				ed[hav]=T+1;
			}else{
				it[hav]++;ins.PB(hav);
			}
		}
		for(auto u:ins){
			q[v[u][it[u]]].emplace(u);
			if(!vis[v[u][it[u]]])s.emplace(v[u][it[u]]),vis[v[u][it[u]]]=1;
		}
		V<int> era;
		for(auto u:s){
			if(q[u].empty())era.PB(u);
		}
		for(auto u:era){
			vis[u]=0;s.erase(u);
		}
		T++;
//		FOR(i,1,k)cout<<it[i]<<' ';
//		cout<<'\n';
		if(s.empty())break;
	}
	FOR(i,1,k)cout<<ed[i]<<' ';
	RE 0;
}