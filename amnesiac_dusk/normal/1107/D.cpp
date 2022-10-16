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

vector<bool> a[5200];
vector<bool> lol[256];
void solve()
{
	for(int i=0; i<10; i++)
		lol['0'+i]={(bool)(i/8),(bool)((i/4)&1),(bool)((i/2)&1),(bool)(i&1)};
	lol['A']={1,0,1,0};
	lol['B']={1,0,1,1};
	lol['C']={1,1,0,0};
	lol['D']={1,1,0,1};
	lol['E']={1,1,1,0};
	lol['F']={1,1,1,1};
	int n;
	string s;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>s;
		for(int j=0; j<s.length(); j++)
			for(bool te:lol[s[j]])
				a[i].pb(te);
	}
	vector<pii> pfs;
	int nn=n;
	for(int i=2; i*i<=nn; i++) {
		if(nn%i==0) {
			int ii=i;
			while(nn%i==0)
			{
				pfs.pb({ii,i});
				nn/=i;
				ii*=i;
			}
		}
	}
	int ans=1;
	if(nn!=1)
		pfs.pb({nn,nn});
	for(auto &fac:pfs) {
		bool v=1;
		for(int i=0; i<n&&v; i+=fac.fi)
			for(int j=0; j<n&&v; j+=fac.fi) {
				bool te=a[i][j];
				for(int k=i; k<i+fac.fi&&v; k++)
					for(int l=j; l<j+fac.fi&&v; l++)
						if(te!=a[k][l])
							v=0;
			}
		if(v)
			ans*=fac.se;
	}
	cout<<ans<<endl;
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