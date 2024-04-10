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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
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

int f[6];
int dp[7][1000005];
void solve() {
	int k,te,q;
	cin>>k;
	rep(i,0,6)
		cin>>f[i];
	cin>>te>>q;
// 	k=999999,q=999999;
	memset(dp,0x3f,sizeof(dp));
	int pol=q;
	dp[0][q]=0;
	int mrem=0;
	int hol=0;
	for(int j=0; j<6; j++) {
		int lim=pol;
		int mrem=q-hol*k;
		rep(k,0,j)
			mrem/=10;
		mrem--;
		mrem=max(mrem,0LL);
		lim++;
		for(int star=mrem; star<=lim; star++) {
			for(int tot=star%10; tot<=star; tot+=10) {
				int num=(tot+8)/9,score=dp[j][star];
				if(num>k)
					break;
				if(num<k||tot%3==0)
					score-=(tot/3)*f[j];
				else
					score-=(tot/9)*3*f[j];
				dp[j+1][(star-tot)/10]=min(score,dp[j+1][(star-tot)/10]);
			}
		}
		hol=hol*10+9;
		pol/=10;
	}
	cout<<-dp[6][0]<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}