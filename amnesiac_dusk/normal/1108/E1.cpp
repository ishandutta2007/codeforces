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

int a[100005];
int b[100005];
vector<pii> segs;
void solve()
{
	int n,m,l,r;
	cin>>n>>m;
	int ansd=0;
	int mmm=1e9,mmi=-1e9;
	for(int i=1; i<=n; i++)
	{	cin>>a[i];
	mmm=min(mmm,a[i]);
	mmi=max(mmi,a[i]);
	}
	ansd=mmi-mmm;
	for(int i=1; i<=m; i++) {
		cin>>l>>r;
		segs.pb({l,r});
	}
	vector<int> ans;
	for(int i=1; i<=n; i++) {
		vector<int> indi;
		fill(b,b+n+1,0);
		for(int j=0; j<m; j++) {
			auto te=segs[j];
			if(te.fi>i||te.se<i) {
				b[te.fi]--;
				b[te.se+1]++;
				indi.pb(j+1);
			}
		}
		int minx=1e9,maxx=-1e9;
		for(int j=1; j<=n; j++) {
			b[j]+=b[j-1];
			minx=min(b[j]+a[j],minx);
			maxx=max(b[j]+a[j],maxx);
		}
		if(maxx-minx>ansd) {
			ansd=maxx-minx;
			ans=indi;
		}
	}
	cout<<ansd<<endl;
	cout<<ans.size()<<endl;
	for(int i:ans)
		cout<<i<<" ";
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