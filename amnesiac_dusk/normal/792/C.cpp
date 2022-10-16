//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
void pr(string s) {
	for(int i=0; i<sz(s); i++)
		s[i]+='0';
	cout<<s;
}
void solve() {
	string s;
	cin>>s;
	int sum=0;
	int one=0,two=0;
	for(int i=0; i<s.length(); i++) {
		s[i]-='0';
		sum+=s[i];
		if(s[i]%3==1)
			one++;
		else if(s[i]%3==2)
			two++;
	}
	if(sum%3==0) {
		pr(s);
	} else {
		if(sz(s)==1) {
			cout<<-1<<endl;
			return;
		}
		int te=sum%3;
		for(int i=sz(s)-1; i>0; i--) {
			if(s[i]%3==te)
			{
				pr(s.substr(0,i));
				pr(s.substr(i+1));
				return;
			}
		}
		if(s[0]%3==te&&(s[1]!=0||sz(s)==2)) {
			pr(s.substr(1));
			return;
		}
		int ts=(2*te)%3;
		trace(ts);
		for(int i=sz(s)-1; i>0; i--) {
			if(s[i]%3==ts) {
				for(int j=i-1; j>0; j--) {
					if(s[j]%3==ts) {
						pr(s.substr(0,j));
						pr(s.substr(j+1,i-j-1));
						pr(s.substr(i+1));
						return;
					}
				}
			}
		}
		trace(ts);
		if(s[0]%3==te) {
			for(int i=1; i<sz(s); i++)
				if(s[i]!=0) {
					pr(s.substr(i));
					return;
				}
		}
		if(s[0]%3==ts) {
			trace(ts);
			int ii=0;
			int jj=0;
			for(int i=1; i<sz(s); i++) {
				if(s[i]) {
					if(jj==0)
						jj=i;
					ii++;
				}
			}
			if(ii<=1) {
				for(int i=0; i<sz(s); i++)
					if(s[i]==0) {
						cout<<0<<endl;
						return;
					}
				cout<<-1<<endl;
				return;
			}
			for(int i=1; i<sz(s); i++) {
				if(s[i]%3==ts) {
					if(i==jj) {
						for(int k=i+1; k<sz(s); k++)
							if(s[k]) {
								pr(s.substr(k));
								return;
							}
					} else {
						pr(s.substr(jj,i-jj));
						pr(s.substr(i+1));
					}
					return;
				}
			}
		}
		for(int i=0; i<sz(s); i++)
			if(s[i]==0) {
				cout<<0<<endl;
				return;
			}
		cout<<-1<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}