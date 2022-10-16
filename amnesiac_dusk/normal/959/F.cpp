/*
 * 	Meet me on the battlefield
 * 		Even on the darkest night
 * 			I will be your sword and shield,
 * 				Your camouflage and you will be mine
 * 	Echoes of the shots ring out
 * 		We may be the first to fall
 * 			Everything could stay the same
 * 				Or we could change it all
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const int inf=1e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[100005];
bool b[1<<20];
vector<int> current;
vector<pii> quer[100005];
int anses[100005];
void solve() {
	int n,q,l,x;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=q; i++) {
		cin>>l>>x;
		quer[l].pb({x,i});
	}
	int lol=1;
	current.pb(0);
	b[0]=1;
	for(int i=1; i<=n; i++) {
		if(b[a[i]]) {
			lol=lol<<1;
			if(lol>=mod)
				lol-=mod;
		}
		else
		{
			int nn=current.size();
			for(int j=0; j<nn; j++) {
				b[a[i]^current[j]]=1;
				current.pb(a[i]^current[j]);
			}
		}
		for(pii &j:quer[i]) {
			if(b[j.fi])
				anses[j.se]=lol;
		}
	}
	for(int i=1; i<=q; i++)
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
/**/