#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
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
const ll infl=0x3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int a[200005];
int one[200005],two[200005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		one[i]=0;
		two[i]=0;
		char tul;
		cin>>tul;
		a[i]=tul;
	}
	set<int> lol;
	fr(i,1,n) {
		if(lol.empty())
			lol.insert(a[i]);
		else {
			auto it=lol.upper_bound(a[i]);
			if(it==lol.end())
				continue;
			if(it!=lol.begin())
				lol.erase(it);
			lol.insert(a[i]);
		}
	}
	if(sz(lol)>2) {
		cout<<'-'<<endl;
		return;
	}
	int maxi=0;
	fr(i,1,n) {
		maxi=max(maxi,a[i]);
		if(maxi>a[i]) {
			one[i]=1;
		}
	}
	int mini=a[n];
	for(int i=n; i>0; i--) {
		mini=min(mini,a[i]);
		if(mini<a[i]) {
			two[i]=1;
		}
	}
	mini=0;
	for(int i=n; i>0; i--) {
		if(a[i]<mini) {
			one[i]=1;
		}
		if(one[i]) {
			mini=max(mini,a[i]);
		}
	}
	mini=infl;
	fr(i,1,n) {
		if(a[i]>mini) {
			two[i]=1;
		}
		if(two[i]) {
			mini=min(mini,a[i]);
		}
	}
	vi o,t;
	fr(i,1,n) {
		if(one[i])
			o.pb(a[i]);
		if(two[i])
			t.pb(a[i]);
		if(one[i]&&two[i]) {
			cout<<'-'<<endl;
			return;
		}
	}
	for(int i=1; i<sz(o); i++)
		if(o[i]<o[i-1]) {
			cout<<'-'<<endl;
			return;
		}
	for(int i=1; i<sz(t); i++)
		if(t[i]<t[i-1]) {
			cout<<'-'<<endl;
			return;
		}
	if(sz(t)&&sz(o)&&t[0]<o.back()) {
		cout<<'-'<<endl;
		return;
	}
	fr(i,1,n) {
		if(one[i]) {
			cout<<1;
		} else if(two[i])
			cout<<2;
		else
			cout<<1;
	}
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}