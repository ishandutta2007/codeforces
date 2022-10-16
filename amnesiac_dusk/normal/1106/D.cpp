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
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi gra[100005];
bool vis[100005];
bool inq[100005];
void solve()
{
	int n,m,u,v;
	priority_queue<int,vector<int>,greater<int>> hola;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	hola.push(1);
	inq[1]=1;
	while(!hola.empty()) {
		int te=hola.top();
		hola.pop();
		cout<<te<<" ";
		for(int i:gra[te]) {
			if(!inq[i]) {
				inq[i]=1;
				hola.push(i);
			}
		}
	}
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