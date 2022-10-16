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

int dp[200005][3];
int pre[200005][3];
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s+='R';
	int lol[256];
	lol['R']=1;
	lol['G']=2;
	lol['B']=4;
	char lul[8];
	lul[1]='R';
	lul[2]='G';
	lul[4]='B';
	int ans=0;
	for(int i=1; i<n; i++) {
		if(s[i]==s[i-1]) {
			if(s[i]!=s[i+1])
				s[i]=lul[7-lol[s[i-1]]-lol[s[i+1]]];
			else if(s[i]=='R')
				 s[i]='G';
			else if(s[i]=='G')
				s[i]='R';
			else
				s[i]='R';
			ans++;
		}
	}
	cout<<ans<<endl<<s.substr(0, n)<<endl;
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