/*
 * 	Yet I'm feeling like
 * 		There is no better place than right by your side
 * 			I had a little taste
 * 				And I'll only spoil the party anyway
 * 					'Cause all the girls are looking fine
 * 						But you're the only one on my mind
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
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[100005][205];
vector<pair<pii,pii>> enve1,enve2;
void solve()
{
	int n,m,k,s,t,d,w;
	cin>>n>>m>>k;
	for(int i=1; i<=k; i++) {
		cin>>s>>t>>d>>w;
		enve1.pb({{s,t},{d,w}});
		enve2.pb({{s,t},{d,w}});
	}
	sort(all(enve1));
	sort(all(enve2),[](auto &a, auto &b) -> bool
			{
		return a.fi.se<b.fi.se;
			});
	auto cmp=[](auto &a, auto &b)-> bool
			{
		if(a.se.se!=b.se.se)
			return a.se.se<b.se.se;
		if(a.se.fi!=b.se.fi)
			return a.se.fi<b.se.fi;
		if(a.fi.fi!=b.fi.fi)
			return a.fi.fi<b.fi.fi;
		return a.fi.se<b.fi.se;
			};
	set<pair<pii,pii>,decltype(cmp)> active(cmp);
	for(int i=1; i<=n+1; i++)
		for(int j=0; j<=m; j++)
			dp[i][j]=inf;
	dp[1][0]=0;
	for(int i=1,j=0,l=0; i<=n; i++) {
		while(l<k&&enve2[l].fi.se<i) {
			active.erase(enve2[l]);
			l++;
		}
		while(j<k&&enve1[j].fi.fi<=i) {
			active.insert(enve1[j]);
			j++;
		}
		if(active.size())
		{
			auto ho=*(--active.end());
			for(int j=0; j<=m; j++) {
				dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
				dp[ho.se.fi+1][j]=min(dp[i][j]+ho.se.se,dp[1+ho.se.fi][j]);
			}
		} else {
			for(int j=0; j<=m; j++) {
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			}
		}
	}
	ll ans=inf;
	for(int i=0; i<=m; i++) {
		ans=min(dp[n+1][i],ans);
	}
	cout<<ans<<endl;
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