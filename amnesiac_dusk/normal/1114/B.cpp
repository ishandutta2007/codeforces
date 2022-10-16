/*
 * 	Meet me on the battlefield
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
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const int inf=1e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<pii> a;
	for(int i=1; i<=n; i++) {
		int te;
		cin>>te;
		a.pb({te,i});
	}
	sort(all(a));
	reverse(all(a));
	vector<pii> b;
	ll sum=0;
	for(int i=0; i<m*k; i++)
	{
		sum+=a[i].fi;
		b.pb(a[i]);
	}
	sort(all(b),[](pii &a,pii &b) {
		return a.se<b.se;
	});
	cout<<sum<<endl;
	for(int i=0; i<m*k; i++) {
		if(i+1!=m*k)
			if((i+1)%m==0)
				cout<<b[i].se<<" ";
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/