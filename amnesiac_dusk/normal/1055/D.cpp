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
const int mod=998244353;
//const int mod=1000000007;
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


string s[3005],t[3005];
string from[3005],to[3005];
int mi[3005],ma[3005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>s[i];
	fr(i,1,n)
		cin>>t[i];
	string fro="",tom;
	string repr,suf;
	fr(i,1,n) {
		mi[i]=infl;
		ma[i]=0;
		if(s[i]!=t[i]) {
			for(int j=0; j<sz(s[i]); j++) {
				if(s[i][j]!=t[i][j]) {
					mi[i]=min(mi[i],j);
					ma[i]=j;
				}
			}
			from[i]=s[i].substr(mi[i],ma[i]-mi[i]+1);
			to[i]=t[i].substr(mi[i],ma[i]-mi[i]+1);
			string curpr=s[i].substr(0, mi[i]),cursuf=s[i].substr(ma[i]+1);
			reverse(all(curpr));
			if(fro=="") {
				repr=curpr;
				suf=cursuf;
			} else {
				if(sz(repr)>sz(curpr))
					swap(repr,curpr);
				for(int j=0; j<sz(repr); j++)
					if(repr[j]!=curpr[j]) {
						repr=repr.substr(0, j);
						break;
					}
				if(sz(suf)>sz(cursuf))
					swap(suf,cursuf);
				for(int j=0; j<sz(suf); j++)
					if(suf[j]!=cursuf[j]) {
						suf=suf.substr(0, j);
						break;
					}

			}
			fro=from[i];
			tom=to[i];
		}
	}
	fr(i,1,n) {
		if(s[i]!=t[i])
			if(from[i]!=fro||to[i]!=tom) {
				cout<<"NO"<<endl;
				return;
			}
	}
	reverse(all(repr));
	fro=repr+fro+suf;
	tom=repr+tom+suf;
	fr(i,1,n) {
		mi[i]-=sz(repr);
		ma[i]+=sz(suf);
	}
	vi lcp(sz(fro));
	for(int i=1,j=0; i<sz(fro);) {
		if(fro[i]==fro[j]) {
			lcp[i]=++j;
			i++;
		} else if(j!=0) {
			j=lcp[j-1];
		} else {
			i++;
		}
	}
//	trace(fro,tom);
	string tolol="a",tolob="b";
	int nposo=tolol.find(tolob);
	fr(i,1,n) {
		int ff=s[i].find(fro);
//		for(int j=0,k=0; j<sz(s[i]); ) {
//			if(s[i][j]==fro[k]) {
//				j++;
//				k++;
//			}
//			if(k==sz(fro)) {
//				ff=j-sz(fro);
//				break;
//			} else if(j<sz(s[i])&&s[i][j]!=fro[k]) {
//				if(k!=0)
//					k=lcp[k-1];
//				else
//					j++;
//			}
//		}
		if((s[i]==t[i]&&ff!=nposo)||(s[i]!=t[i]&&ff!=mi[i])) {
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	cout<<fro<<endl<<tom<<endl;
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