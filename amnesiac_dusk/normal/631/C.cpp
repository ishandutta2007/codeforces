/*
 * 	I believe if I knew where I was going Id lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today its okay to be not okay
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
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}

multiset<int> hol;
int a[200005];
vector<pair<int,pii>> oper;
void solve()
{
	int n,m,ord,pre;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=m; i++) {
		cin>>ord>>pre;
		while(!oper.empty()&&oper.back().se.se<=pre) {
			oper.pop_back();
		}
		if(!oper.empty())
			oper.back().se.fi=pre;
		oper.push_back({ord,{0,pre}});
	}
	for(int i=1; i<=oper[0].se.se; i++) {
		hol.insert(a[i]);
	}
	for(auto &te:oper) {
		if(te.fi==1) {
			for(int j=te.se.se; j>te.se.fi; j--) {
				a[j]=*(--hol.end());
				hol.erase(--hol.end());
			}
		} else {
			for(int j=te.se.se; j>te.se.fi; j--) {
				a[j]=*(hol.begin());
				hol.erase(hol.begin());
			}
		}
	}
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
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