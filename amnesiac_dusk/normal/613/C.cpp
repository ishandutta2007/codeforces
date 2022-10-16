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
//const int mod=998244353;
const int mod=1000000007;
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

int cnt[256];
void solve() {
	int n,oo=0;
	cin>>n;
	rep(i,'a',n+'a') {
		cin>>cnt[i];
		if(cnt[i]&1)
			oo++;
	}
	if(n==1) {
		cout<<cnt['a']<<endl<<string(cnt['a'],'a')<<endl;
	} else if(oo>1) {
		cout<<0<<endl;
		for(char i='a'; i<n+'a'; i++)
			rep(j,0,cnt[i])
				cout<<i;
	} else {
		int sum=accumulate(cnt+'a',cnt+n+'a',0LL);
		int ans=sum;
		rep(i,'a',n+'a')
			ans=gcd(ans,cnt[i]);
		vector<char> lol;
		cout<<ans<<endl;
		if(ans&1) {
		} else {
			ans>>=1;
		}
		string ans1="",ans2="",ans3="";
		for(char i='a'; i<n+'a'; i++) {
			rep(j,0,cnt[i]/(2*ans)) {
				ans1+=i;
				ans3+=i;
			}
			if((cnt[i]/ans)&1) {
				ans2+=i;
			}
		}
		reverse(all(ans3));
		string anser=ans1+ans2+ans3;
		rep(i,0,ans) {
			cout<<anser;
		}
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}