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

const int N=3e5+5;
vi ls,rs;
double pref[N],sy;
double getx(int x,int y, int sx) {
	if(sx==x)
		return sx;
	return sx-(sy*(sx-x+0.0))/(sy-y);
}
int n;
double getvalue(double pos) {
	int lo=0,hi=n-1,mid=(1+lo+hi)/2;
	if(ls[lo]>pos)
		return 0;
	if(rs[hi]<pos)
		return pref[n];
	while(lo<hi) {
		if(ls[mid]>pos) {
			hi=mid-1;
		} else
			lo=mid;
		mid=(lo+hi+1)/2;
	}
	if(rs[mid]<=pos) {
		return pref[mid+1];
	} else {
		return max((double)0.0,pref[mid]+pos-ls[mid]);
	}
}
void solve() {
	int a,b,l,r;
	cin>>sy>>a>>b>>n;
	fr(i,1,n) {
		cin>>l>>r;
		ls.pb(l);
		rs.pb(r);
		pref[i]=r-l+pref[i-1];
	}
	int q;
	cin>>q;
	while(q--) {
		int x,y;
		cin>>x>>y;
		double sp=getx(x,y,a);
		double ep=getx(x,y,b);
		cout<<((y-sy+0.0)/y)*(getvalue(ep)-getvalue(sp))<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}