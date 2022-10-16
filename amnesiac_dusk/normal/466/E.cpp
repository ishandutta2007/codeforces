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
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int par[100001];
int t2[100001][2];
int lcadp[100001][18],ddp[100001][18];
int depth[100001];
int t3[100001][3];
vector<int> gra[100001];
void dfs(int fr, int at, int deep) {
	lcadp[at][0]=fr;
	depth[at]=deep;
	for(int i:gra[at])
		dfs(at,i,deep+1);
}
void solve()
{
	int n,m;
	cin>>n>>m;
	int ct=0,typ,x,y;
	for(int i=1; i<=m; i++) {
		cin>>typ;
		if(typ==1) {
			cin>>x>>y;
			par[x]=y;
			gra[y].pb(x);
			ddp[x][0]=i;
		} else if(typ==2) {
			++ct;
			cin>>t2[ct][0];
			t2[ct][1]=i;
		} else {
			cin>>x>>y;
			t3[i][0]=x;
			t3[i][1]=t2[y][0];
			t3[i][2]=t2[y][1];
		}
	}
	for(int i=1; i<=n; i++)
		if(!par[i])
			dfs(i,i,0);
	for(int j=1; j<18; j++)
		for(int i=1; i<=n; i++) {
			lcadp[i][j]=lcadp[lcadp[i][j-1]][j-1];
			ddp[i][j]=max(ddp[i][j-1],ddp[lcadp[i][j-1]][j-1]);
		}
	for(int i=1; i<=m; i++) {
		if(t3[i][0]) {
			int u=t3[i][1],v=t3[i][0],dist=0;
			for(int j=17; j>=0; j--)
				if(depth[lcadp[u][j]]>=depth[v]) {
					dist=max(dist,ddp[u][j]);
					u=lcadp[u][j];
				}
			if(u!=v||dist>t3[i][2])
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
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