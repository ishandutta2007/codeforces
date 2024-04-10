/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


set<int> gra[200005];
int degrees[200005];
bool rejected[200005];
void solve() {
	int n,m,k,u,v;
	cin>>n>>m>>k;
	vector<pii> edges;
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		edges.pb({u,v});
		gra[u].insert(v);
		gra[v].insert(u);
		degrees[u]++;
		degrees[v]++;
	}
	queue<int> rejection;
	int ans=n;
	for(int i=1; i<=n; i++)
		if(degrees[i]<k)
		{
			ans--;
			rejection.push(i);
			rejected[i]=1;
		}
	while(!rejection.empty())
	{
		int te=rejection.front();
		rejection.pop();
		for(int i:gra[te])
		{
			degrees[i]--;
			if(degrees[i]==k-1)
			{
				ans--;
				rejection.push(i);
				rejected[i]=1;
			}
		}
	}
	vector<int> anses;
	for(int j=m-1; j>=0; j--)
	{
		anses.pb(ans);
		if((!rejected[edges[j].fi])&&(!rejected[edges[j].se]))
		{
			degrees[edges[j].se]--;
			degrees[edges[j].fi]--;
			gra[edges[j].fi].erase(edges[j].se);
			gra[edges[j].se].erase(edges[j].fi);
			if(degrees[edges[j].fi]==k-1)
			{
				ans--;
				rejection.push(edges[j].fi);
				rejected[edges[j].fi]=1;
			}
			if(degrees[edges[j].se]==k-1)
			{
				ans--;
				rejection.push(edges[j].se);
				rejected[edges[j].se]=1;
			}
		}
		while(!rejection.empty())
		{
			int te=rejection.front();
			rejection.pop();
			for(int i:gra[te]) {
				degrees[i]--;
				if(degrees[i]==k-1) {
					ans--;
					rejected[i]=1;
					rejection.push(i);
				}
			}
		}
	}
	reverse(all(anses));
	for(int i:anses)
		cout<<i<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}