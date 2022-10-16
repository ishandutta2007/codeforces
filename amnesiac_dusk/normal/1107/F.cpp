/*
 * 	I believe if I knew where I was going I'd lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today it's okay to be not okay
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
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

struct pla{
	int a,b,k,d;
};
int ans[505][505];
vector<pla> plans;
void solve()
{
	int n;
	cin>>n;
	fr(i,1,n) {
		pla te;
		cin>>te.a>>te.b>>te.k;
		te.d=max(te.a-te.b*te.k,0LL);
		plans.pb(te);
	}
	sort(all(plans),[](pla &a,pla &b) {
//		if(a.b!=b.b)
			return a.b>b.b;
//		return a.k<b.k;
	});
	int finan=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans[i+1][j]=max(ans[i+1][j],ans[i][j]+plans[i].d);
			ans[i+1][j+1]=max(ans[i+1][j+1],ans[i][j]+plans[i].a-plans[i].b*j);
		}
	}
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			finan=max(finan,ans[i][j]);
	cout<<finan<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}