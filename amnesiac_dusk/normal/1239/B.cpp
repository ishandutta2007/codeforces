#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

int pr[600005];
void solve() {
	int n;
	string s;
	cin>>n>>s;
	int o=0;
	for(char i:s)
		if(i=='(')
			o++;
		else
			o--;
	if(o) {
		cout<<"0\n1 1"<<endl;
		return;
	}
	for(int i=0; i<sz(s); i++)
		if(s[i]=='(')
			pr[i+1]=pr[i]+1;
		else
			pr[i+1]=pr[i]-1;
	int mi=*min_element(pr+1, pr+n+1);
	int ans=0;
	fr(i,1,n)
		if(pr[i]==mi)
			ans++;
	pii ind={1,1};
	int cntr2=0;
	int last=-1,cntr=0;
	pii hans={1,1};
	fr(i,n+1,2*n)
		pr[i]=pr[i-n];
	s+=s;
	n+=n;
	fr(i,1,n) {
		if(s[i-1]=='('&&last==-1)
			last=i;
		if(s[i-1]==')'&&last!=-1) {
			if(cntr2<cntr) {
				cntr2=cntr;
				hans={last,i};
			}
		}
		if(pr[i]==mi+2)
			cntr++;
		if(pr[i]<=mi+1) {
			last=-1;
			cntr=0;
		}
	}
	ans+=cntr2;
	ind=hans;
	int lasta=min_element(pr+1, pr+n+1)-pr;
	cntr=0;
	cntr2=0;
	fr(i,lasta,n) {
		if(s[i-1]=='('&&lasta==-1)
			lasta=i;
		if(s[i-1]==')'&&lasta!=-1) {
			if(cntr2<cntr) {
				cntr2=max(cntr,cntr2);
				hans={lasta,i};
			}
		}
		if(pr[i]==mi+1)
			cntr++;
		if(pr[i]==mi) {
			cntr=0;
			lasta=-1;
		}
	}
	if(ans<cntr2) {
		ans=cntr2;
		ind=hans;
	}
	n/=2;
	if(ind.se>n) {
		ind.se-=n;
	}
	if(ind.fi>n) {
		ind.fi-=n;
	}
	cout<<ans<<endl;
	cout<<ind.fi<<" "<<ind.se<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}