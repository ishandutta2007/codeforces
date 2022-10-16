/*
 * 	I believe if I knew where I was going Id lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today its okay to be not okay
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}

vector<pii> s,t,tom;
int lps[200005],here[200005];
void solve()
{
	int n,m,l,c;
	cin>>n>>m;
	string temp;
	for(int i=1; i<=n; i++) {
		cin>>temp;
		l=stoi(temp.substr(0,sz(temp)-2));
		c=temp[sz(temp)-1];
		if(!t.empty()&&t.back().se==c) {
			t.back().fi+=l;
		} else
			t.push_back({l,c});
	}
	for(int i=1; i<=m; i++) {
		cin>>temp;
		l=stoi(temp.substr(0,sz(temp)-2));
		c=temp[sz(temp)-1];
		if(!s.empty()&&s.back().se==c) {
			s.back().fi+=l;
		} else
			s.push_back({l,c});
	}
	int ans=0;
	if(s.size()==1) {
		for(auto &te:t)
			if(te.se==s[0].se)
				ans+=max(0LL,te.fi-s[0].fi+1);
	} else {
		for(int i=1; i<sz(s)-1; i++) {
			tom.pb(s[i]);
		}
		if(sz(tom)!=0) {
			for(int i=1,j=0; i<sz(tom); i++) {
				if(tom[i]==tom[j]) {
					lps[i]=++j;
				} else if(j!=0) {
					j=lps[j-1];
					i--;
				}
			}
			for(int i=0,j=0; i<sz(t); ) {
				if(tom[j]==t[i]) {
					i++,j++;
				}
				if(j==sz(tom)) {
					here[i-sz(tom)]=1;
					j=lps[j-1];
				} else if(i<sz(t)&&t[i]!=tom[j]) {
					if(j!=0)
						j=lps[j-1];
					else
						i++;
				}
			}
		} else
			for(int i=0; i<sz(t); i++) {
				here[i]=1;
			}
		for(int i=1; i+sz(tom)<sz(t); i++)
			if(here[i])
				if(t[i-1].se==s[0].se&&t[i+sz(tom)].se==s.back().se)
					if(t[i-1].fi>=s[0].fi&&t[i+sz(tom)].fi>=s.back().fi)
						ans++;
	}
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}