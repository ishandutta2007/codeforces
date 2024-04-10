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
struct seg
{
	int l,r;
	int sum,pref,suf,sub;
};
int d[300005],p[300005];
void solve() {
	int n,a;
	cin>>n>>a;
	auto cmp=[](const seg &a,const seg &b) -> bool {
		return a.l<b.l;
	};
	set<seg,decltype(cmp)> hol(cmp);
	vi hola;
	int ans=0;
	fr(i,1,n) {
		cin>>d[i]>>p[i];
		p[i]=a-p[i];
		ans=max(ans,p[i]);
	}
	for(int i=1; i<=n; i++)
		hol.insert(seg{i,i,p[i],max(0LL,p[i]),max(0LL,p[i]),max(0LL,p[i])});
	fr(i,2,n) {
		hola.pb(i);
	}
	sort(all(hola),[](int i, int j) {
		return d[i]-d[i-1]<d[j]-d[j-1];
	});
	for(int i:hola) {
		auto te=hol.lower_bound(seg{i,0,0,0,0,0});
		auto hi=*te;
		--te;
		auto lo=*te;
		hol.erase(hi);
		hol.erase(lo);
		lo.r=hi.r;
		lo.sub=max({lo.sub,hi.sub,lo.suf+hi.pref});
		lo.pref=max(lo.pref,lo.sum+hi.pref);
		lo.suf=max(hi.suf,lo.suf+hi.sum);
		lo.sum+=hi.sum;
		hol.insert(lo);
		ans=max(ans,lo.sub-((d[i]-d[i-1])*(d[i]-d[i-1])));
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