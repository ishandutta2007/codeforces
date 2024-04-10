/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=490019;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
#define EPS   1E-10
struct line
{
  ll m, c;
  line(ll _M = 0, ll _C = 0) : m(_M), c(_C) {}
};
struct cht
{
    vector<line> lines;
    cht() { lines.clear(); }
    f80 get_x(line l1, line l2)
    { return (f80(1) * l1.c - l2.c) / (f80(1) * l2.m - l1.m); }
    bool bad(line l1, line l2, line l3)
    {
        f80 x12 = get_x(l1,l2);
        f80 x13 = get_x(l1,l3);
        return (x12 >= x13);
    }
    void add_line(ll M, ll C)
    {
        line l(M,C);
        while(sz(lines) >= 2 && bad(lines[sz(lines) - 2], lines[sz(lines) - 1], l))
        lines.pop_back();
        lines.pb(l);
    }
    ll eval(line L, ll x) { return (x * L.m + L.c); }
    ll getMin(ll x)
    {
        int lo = 0, hi = sz(lines);
        assert(lo != hi);
        while(hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            ll v1 = eval(lines[mid - 1], x);
            ll v2 = eval(lines[mid], x);
            if(v1 < v2) hi = mid;
            else lo = mid;
        }
        return eval(lines[lo], x);
    }
}dp;
const int N=3e5+5,bls=2000;
int anses[N];
vector<pair<pii,pii>> thisb;
int linum[N];
int blk[N];
vector<pii> queries[150];
void solve() {
	int n;
	cin>>n;
	vector<pair<pii,pii>> lines;
	fr(i,1,n) {
		blk[i]=(i-1)/bls;
		int ty;
		cin>>ty;
		if(ty==1) {
			int a,b;
			cin>>a>>b;
			linum[i]=sz(lines);
			trace(a,b,i,n);
			lines.pb({{a,b},{i,n}});
		} else if(ty==2) {
			int ii;
			cin>>ii;
			lines[linum[ii]].se.se=i;
		} else {
			int q;
			cin>>q;
			queries[blk[i]].pb({i,q});
		}
	}
	sort(all(lines));
	fr(i,blk[1],blk[n]) {
		dp.lines.clear();
		thisb.clear();
		for(auto &j:lines) {
			if(blk[j.se.fi]<i&&i<blk[j.se.se])
				dp.add_line(-j.fi.fi,-j.fi.se);
			if(blk[j.se.fi]==i||blk[j.se.se]==i)
				thisb.pb(j);
		}
		for(auto j:queries[i]) {
			int ans=-infl;
			if(dp.lines.size())
				ans=-dp.getMin(j.se);
			for(auto lin:thisb) {
				trace(j.fi,lin.se.fi,lin.se.se);
				if(lin.se.fi<=j.fi&&j.fi<=lin.se.se)
					ans=max(ans,lin.fi.fi*j.se+lin.fi.se);
			}
			if(ans!=-infl)
				cout<<ans<<endl;
			else
				cout<<"EMPTY SET"<<endl;
		}
	}

}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}