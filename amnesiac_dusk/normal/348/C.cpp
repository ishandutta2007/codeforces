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
//#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int bs=400;
bool type[100001];
signed mapp[100001];
signed inter[100000/bs+1][100001];
bool is[100000/bs+1][100001];
ll a[100001];
ll larval[100000/bs+1];
ll inc[100000/bs+1];
vector<int> indices[100001];
void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int larno=0,tem;
	for(int i=1; i<=m; i++) {
		int te;
		cin>>te;
		if(te>bs) {
			++larno;
			type[i]=1;
			mapp[i]=larno;
			for(int j=1; j<=te; j++) {
				cin>>tem;
				larval[larno]+=a[tem];
				indices[i].pb(tem);
				is[larno][tem]=1;
			}
		} else {
			for(int j=1; j<=te; j++) {
				cin>>tem;
				indices[i].pb(tem);
			}
		}
	}
	for(int i=1; i<=larno; i++)
		for(int j=1; j<=m; j++)
			for(int k:indices[j])
				if(is[i][k])
					inter[i][j]++;
	char tol;
	int num;
	ll val;
	while(q--) {
		cin>>tol;
		if(tol=='?') {
			cin>>num;
			if(type[num]) {
				cout<<larval[mapp[num]]<<endl;
			} else {
				ll sum=0;
				for(int i:indices[num])
					sum+=a[i];
				for(int i=1; i<=larno; i++)
					sum+=inc[i]*inter[i][num];
				cout<<sum<<endl;
			}
		} else {
			cin>>num>>val;
			if(type[num]) {
				inc[mapp[num]]+=val;
				for(int i=1; i<=larno; i++)
					larval[i]+=val*inter[i][num];
			} else {
				for(int j:indices[num])
					a[j]+=val;
				for(int i=1; i<=larno; i++)
					larval[i]+=val*inter[i][num];
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