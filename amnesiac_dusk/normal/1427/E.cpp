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
mt19937_64 rang(69);
//mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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

int invl(int a, int mod) {
	a%=mod;
	int b = mod;
	int p = 1, q = 0;
	while (b > 0) {
		int c = a / b;
		int d;
		d = a;
		a = b;
		b = d % b;
		d = p;
		p = q;
		q = d - c * q;
	}
	return p < 0 ? p + mod : p;
}

void solve() {
//	int x=rng(500000)<<1|1;
	int x;
	cin>>x;
	vi gen={x};
	vector<vi> output;
	set<int> dups;
	while(1) {
		int ron1=gen[rng(sz(gen))];
		int ron2=gen[rng(sz(gen))];
		if(rng(2)<=0) {
			gen.pb(ron1+ron2);
			output.pb({ron1,ron2,0});
		} else {
			gen.pb(ron1^ron2);
			output.pb({ron1,ron2,1});
		}
		if(dups.count(gen.back())) {
			gen.pop_back();
			output.pop_back();
			continue;
		}
		dups.insert(gen.back());
		if(gcd(gen.back(),x)==1) {
			break;
		}
	}
	int a=x,b=gen.back();
	int q=invl(b,a);
	int p=(b*q-1)/a;
	trace(p,q);
	int aa=a,bb=b,res=0;
	output.pb({a,a});
	while(p>0) {
		if(p&1) {
			output.pb({aa,res,0});
			res+=aa;
		}
		output.pb({aa,aa,0});
		aa+=aa;
		p>>=1;
	}
	int res2=0;
	while(q>0) {
		if(q&1) {
			output.pb({bb,res2,0});
			res2+=bb;
		}
		output.pb({bb,bb,0});
		bb+=bb;
		q>>=1;
	}
	trace(a,b,p,q);
	aa=res,bb=res2;
	swap(aa,bb);
	if(aa%2==0) {
		output.pb({bb,bb,0});
		output.pb({aa,bb,0});
		output.pb({aa+bb,bb+bb,1});
	} else {
		output.pb({aa,bb,1});
	}
	trace(aa,bb);
	cout<<sz(output)<<endl;
	for(auto i:output) {
		if(i[2]==0)
			cout<<i[0]<<" + "<<i[1]<<endl;
		else
			cout<<i[0]<<" ^ "<<i[1]<<endl;
	}
	return;




	int mops=0,mm=0;
	double worst=0;
	for(int x=3; x<=999999; x+=2) {
		clk=clock();
		vi gen={x};
		vector<vi> output;
		set<int> dups;
		while(1) {
			int ron1=gen[rng(sz(gen))];
			int ron2=gen[rng(sz(gen))];
			if(rng(2)<=0) {
				gen.pb(ron1+ron2);
				output.pb({ron1,ron2,0});
			} else {
				gen.pb(ron1^ron2);
				output.pb({ron1,ron2,1});
			}
			if(dups.count(gen.back())) {
				gen.pop_back();
				output.pop_back();
				continue;
			}
			dups.insert(gen.back());
			if(gcd(gen.back(),x)==1) {
				break;
			}
		}
		mm=max(mm,gen.back());
		mops=max(mops,sz(gen));
		worst=max(worst,((double)(clock()-clk))/CLOCKS_PER_SEC);
		if((x/2)%100==0) {
			trace(x,worst,mops,mm);
		}
//		trace(output);
	}

	trace(worst);
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}