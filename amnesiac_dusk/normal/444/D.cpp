/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi a4[26][26][26][26];
vi a3[26][26][26];
vi a2[26][26];
vi a1[26];
map<string,int> dp;
void referencor(string &b, vector<int> &t)
{
}
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	int q;
	for(int i=0; i<n; i++)
		s[i]-='a';
	for(int i=0; i<n-3; i++)
		a4[s[i]][s[i+1]][s[i+2]][s[i+3]].pb(i);
	for(int i=0; i<n-2; i++)
		a3[s[i]][s[i+1]][s[i+2]].pb(i);
	for(int i=0; i<n-1; i++)
		a2[s[i]][s[i+1]].pb(i);
	for(int i=0; i<n; i++)
		a1[s[i]].pb(i);
	cin>>q;
	string a,b;
	string te;
	vi *o,*t;
	while(q--) {
		cin>>a>>b;
		if(a<b)
			swap(a,b);
		te=a+" "+b;
		if(dp.count(te)) {
			cout<<dp[te]<<endl;
			continue;
		}
		for(int i=0; i<a.length(); i++)
			a[i]-='a';
		if(a.length()==4)
			o=&a4[a[0]][a[1]][a[2]][a[3]];
		else if(a.length()==3)
			o=&a3[a[0]][a[1]][a[2]];
		else if(a.length()==2)
			o=&a2[a[0]][a[1]];
		else
			o=&a1[a[0]];
		for(int i=0; i<b.length(); i++)
			b[i]-='a';
		if(b.length()==4)
			t=&a4[b[0]][b[1]][b[2]][b[3]];
		else if(b.length()==3)
			t=&a3[b[0]][b[1]][b[2]];
		else if(b.length()==2)
			t=&a2[b[0]][b[1]];
		else
			t=&a1[b[0]];
		if(o->size()==0||t->size()==0)
		{
			cout<<-1<<endl;
			continue;
		}
		if(o->size()>t->size())
			swap(o,t),swap(a,b);
		int ans=inf;
		for(int i:(*o))
		{
			auto lul=lower_bound(all((*t)),i);
			if(lul!=t->end()) {
				int te=*lul;
				int mi=min(te,i);
				int ma=max(te+b.length(),i+a.length());
				ans=min(ans,ma-mi);
			}
		}
		for(int i:(*o))
		{
			int te=*(--upper_bound(all((*t)),i));
			int mi=min(te,i);
			int ma=max(te+b.length(),i+a.length());
			ans=min(ans,ma-mi);
		}
		dp[te]=ans;
		cout<<ans<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}