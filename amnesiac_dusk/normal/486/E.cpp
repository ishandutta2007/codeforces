#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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
typedef float f80;
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

const int N=1e5+5;
int tr[2*N];
int query(int l,int r=1e5+1) {
	int ans=0;
	for(l+=1e5+1,r+=1e5+1; l<r; l>>=1,r>>=1) {
		if(l&1) ans=max(ans,tr[l++]);
		if(r&1) ans=max(ans,tr[--r]);
	}
	return ans;
}
void update(int p, int val) {
	tr[p+=1e5+1]=val;
	for(;p>0; p>>=1) {
		tr[p>>1]=max(tr[p],tr[p^1]);
	}
}
int lo[N],hi[N],a[N],ans[N],cnt[N];
pii change[N];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	multiset<pii> lis;
	for(int i=n; i>0; i--) {
		int val=query(a[i],a[i]+1);
		change[i]={a[i],val};
		update(a[i],query(a[i]+1)+1);
		trace(query(a[i]+1)+1);
	}
	fr(i,1,n) {
		auto it=lis.upper_bound({a[i],0});
		int val=0;
		if(it!=lis.begin()) {
			auto it2=it;
			it2--;
			lis.insert({a[i],(*it2).se+1});
			val=(*it2).se+1;
		} else {
			lis.insert({a[i],1});
			val=1;
		}
		if(it!=lis.end())
			lis.erase(it);
		lo[i]=val;
		hi[i]=query(a[i]+1);
		update(change[i].fi,change[i].se);
		trace(i,lo[i],hi[i]);
	}
	int ans=0;
	fr(i,1,n) {
		ans=max(lo[i]+hi[i],ans);
	}
	fr(i,1,n) {
		if(ans==lo[i]+hi[i])
			cnt[lo[i]]++;
	}
	fr(i,1,n) {
		if(ans==lo[i]+hi[i])
			if(cnt[lo[i]]>1)
				cout<<'2';
			else
				cout<<'3';
		else
			cout<<'1';
	}
}
 
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}