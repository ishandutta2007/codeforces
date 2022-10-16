#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
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
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
 const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

string holve(string s) {
	int n=sz(s);
	vector<vector<int>> p(2,vector<int>(n,0));
	for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
		for(int i=0;i<n;i++) {
			if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
			int L=i-p[z][i], R=i+p[z][i]-!z;
			while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
			if(R>r) l=L,r=R;
		}
	}
	int an=0;
	for(int i=1; i<=sz(s); i++)
		if(p[0][i]==i)
			an=max(an,2*i);
	for(int i=0; i<sz(s); i++)
		if(p[1][i]==i)
			an=max(an,2*i+1);
	return s.substr(0, an);
}
void solve() {
	string s;
	cin>>s;
	int n=sz(s);
	int ans=0;
	for(int i=0; i<sz(s); i++) {
		if(s[i]==s[sz(s)-i-1]) {
			ans+=2;
		} else
			break;
	}
	if(ans==2*sz(s)) {
		cout<<s<<endl;
		return;
	}
	string pro=s.substr(ans/2);
	pro=pro.substr(0,sz(s)-ans);
	string pon=holve(pro);
	reverse(all(pro));
	string ton=holve(pro);
	if(sz(pon)<sz(ton))
		pon=ton;
	cout<<s.substr(0, ans/2)<<pon<<s.substr(sz(s)-ans/2)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	while(t--) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}