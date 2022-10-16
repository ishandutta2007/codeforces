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


vi gra[100005],qu[100005];
int anses[100005];
int a[100005];
vi num[2000005];
int ord[100005],inord[100005];
int ct=0;
int smpf[2000005];
void dfs(int fr, int at)
{
	ord[at]=++ct;
	inord[ct]=at;
	int an=-1,te=a[at],tem;
	while(te!=1) {
		tem=smpf[te];
		if(!num[tem].empty())
			an=max(num[tem].back(),an);
		num[tem].pb(ord[at]);
		te/=tem;
		while(te%tem==0)
			te/=tem;
	}
	if(an!=-1)
		an=inord[an];
	for(int q:qu[at])
		anses[q]=an;
	qu[at].clear();
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i);
	te=a[at];
	while(te!=1) {
		tem=smpf[te];
		num[tem].pop_back();
		te/=tem;
		while(te%tem==0)
			te/=tem;
	}
}
void solve()
{
	for(int i=2; i<2000005; i++)
		if(smpf[i]==0)
			for(int j=i; j<2000005; j+=i)
				smpf[j]=i;
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int u,v;
	for(int i=1; i<n; i++)
		cin>>u>>v,gra[u].pb(v),gra[v].pb(u);
	for(int i=1; i<=q; i++) {
		ct=0;
		int ty;
		cin>>ty;
		if(ty==1) {
			cin>>u;
			qu[u].pb(i);
		}
		else {
			cin>>u>>v;
			dfs(1,1);
			a[u]=v;
		}
	}
	dfs(1,1);
	for(int i=1; i<=q; i++)
		if(anses[i])
			cout<<anses[i]<<endl;
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