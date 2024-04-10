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
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	vector<int> sor;
	for(int i=2; i<=n; i++)
		sor.pb(a[i]-a[i-1]-1);
	sort(all(sor));
	int ans=n;
	for(int i=0; i<n-k; i++) {
		ans+=sor[i];
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