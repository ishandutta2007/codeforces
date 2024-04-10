/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e12;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int t[200005];
int a[3],an[3];
int calcans(int a, int b, int c) {
	int ans=(a+b+c+2)/3;
	if(b>=c) {
		int tran=(b-c)/2;
		b-=tran;
		c+=tran;
	}
	ans=max(ans,b);
	ans=max(ans,c);
	return ans;
}
void solve() {
	int n;
	cin>>n>>a[0]>>a[1]>>a[2];
	multiset<int> crim;
	fr(i,1,n) {
		cin>>t[i];
		if(t[i]>a[0]+a[1]+a[2]) {
			cout<<-1<<endl;
			return;
		}
		crim.insert(t[i]);
	}
	int ans=0,btc=0;
	sort(a,a+3);
	while(!crim.empty()) {
		int bad=*(--crim.end());
		crim.erase((--crim.end()));
		ans++;
		if(crim.empty())
			break;
		if(bad>a[1]+a[2]) {
			continue;
		}
		if(bad>a[0]+a[2]) {
			auto lul=crim.upper_bound(a[0]);
			if(lul!=crim.begin()) {
				lul--;
				crim.erase(lul);
			}
			continue;
		}
		if(bad>a[0]+a[1]&&bad>a[2]) {
			auto lul=crim.upper_bound(a[1]);
			if(lul!=crim.begin()) {
				lul--;
				crim.erase(lul);
			}
			continue;
		}
		// (bad<=a[2] or bad<=a[0]+a[1])
		if(bad>a[2]) {
			auto lul=crim.upper_bound(a[2]);
			if(lul!=crim.begin()) {
				lul--;
				crim.erase(lul);
			}
			continue;
		}
		if(bad<=a[2]&&bad>a[1]) {
			auto lul=crim.upper_bound(a[0]);
			int temp=*lul;
			if(lul!=crim.begin()) {
				lul--;
				crim.erase(lul);
				lul=crim.upper_bound(a[1]);
				if(lul!=crim.begin()) {
					lul--;
					crim.erase(lul);
				} else {
					crim.insert(temp);
					lul=crim.upper_bound(a[0]+a[1]);
					if(lul!=crim.begin()) {
						lul--;
						crim.erase(lul);
					}
				}
			} else {
				lul=crim.upper_bound(a[0]+a[1]);
				if(lul!=crim.begin()) {
					lul--;
					crim.erase(lul);
				}
			}
			continue;
		}
		auto lul=crim.upper_bound(a[1]);
		if(lul!=crim.begin()) {
			lul--;
			crim.erase(lul);
		}
		lul=crim.upper_bound(a[0]);
		if(lul!=crim.begin()) {
			lul--;
			crim.erase(lul);
		}
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}