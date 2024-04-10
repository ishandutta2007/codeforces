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


void solve() {
	int n,p;
	cin>>n>>p;
	vi a;
	fr(i,1,n) {
		int te;
		cin>>te;
		a.pb(te);
	}
	if(p==1) {
		cout<<(n&1)<<endl;
	} else {
		sort(all(a));
		reverse(all(a));
		vi hisab(20,0);
		for(int i=0; i<sz(a); i++) {
			if(i&&a[i]!=a[i-1]) {
				int dif=a[i-1]-a[i];
				int temp=*max_element(all(hisab));
				if(temp) {
					while(dif>0&&hisab.back()==0) {
						for(int j=sz(hisab)-1; j>0; j--)
							hisab[j]=hisab[j-1];
						hisab[0]=0;
						dif--;
					}
				} else
					dif=0;
				trace(dif);
				if(dif) {
					int allo=powm(p,dif+a[i]);
					int tel=dif+a[i];
					int ans=0;
					for(int j:hisab) {
						ans=(ans+j*allo)%mod;
						tel++;
						allo=(allo*p)%mod;
					}
					tel--;
					trace(hisab);
					trace(allo,powm(5,100),tel);
					for(int j=i; j<sz(a); j++)
						ans=(ans-powm(p,a[j]))%mod;
					if(ans<0)
						ans+=mod;
					cout<<ans<<endl;
					return;
				}
			}
			bool done=0;
			for(int j=0; j<sz(hisab); j++) {
				if(hisab[j]) {
					done=1;
					hisab[j]--;
					for(int k=j-1; k>=0; k--)
						hisab[k]=p-1;
					break;
				}
			}
			trace(hisab);
			if(!done)
				hisab[0]++;
		}
		int ans=0;
		for(int i=0; i<sz(hisab); i++)
			ans=(ans+hisab[i]*powm(p,a.back()+i))%mod;
		cout<<ans<<endl;
	}
}

signed main() {
//	cout<<powm(5,100)-11<<endl;
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}