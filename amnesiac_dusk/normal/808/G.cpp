/*
 * 	In an empty-like sky
 * 		What were you looking at?
 * 			I did not even understand
 * 				The reason I woke up
 * 	I was terribly scared
 * 		Of believing
 * 			Because of that
 * 				I've thrown everything away
 * 	It would have been better
 * 		If this world that I hate so much
 * 			Could just disappear
 * 				If I continue to believe
 * 					Won't it hurt me?
 *
 * 	It was your voice
 * 		That has saved me
 * 			And keeps me going
 * 				The feeling that you taught me
 * 					That's true.
 * 	I will scream your name
 * 		Strongly hold your hand
 * 			I will not let go of it anymore
 * 				No matter what the future holds
 * 					If you're with me, I won't run away
 */
#pragma GCC optimize("Ofast")
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
//#define int long long
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

vi dp[100005];
string s,t;
int lps[100005];

int automataprecomputation[100005][26];
int preco(int pref,int curr) {
	return automataprecomputation[pref][curr-'a'];
}
int kmpautomata(int pref, int curr) {
	if(pref!=0&&t[pref]!=curr) {
		pref=lps[pref-1];
		return preco(pref,curr);
	}
	if(t[pref]==curr)
		return pref+1;
	return 0;
}
void solve() {
	int n,m;
	cin>>s>>t;
	n=sz(s);
	m=sz(t);
	for(int i=1,j=0; i<m;) {
		if(t[i]==t[j]) {
			j++;
			lps[i]=j;
			i++;
		}
		else if(j!=0) {
			j=lps[j-1];
		} else
			i++;
	}
	for(int i=0; i<=n; i++)
		dp[i].resize(m+1,-infi);
	dp[0][0]=0;
	for(int i=0; i<m; i++)
		for(int j='a'; j<='z'; j++) {
			automataprecomputation[i][j-'a']=kmpautomata(i,j);
		}
	for(int i=0; i<n; i++) {
//		dp[i][0]=max(dp[i][0],0);
		for(int j=0; j<m; j++) {
			if(dp[i][j]!=-infi) {
				if(s[i]=='?') {
					for(int k='a'; k<='z'; k++) {
						int tem=preco(j, k);
//						if(j==0&&i==0) {
//							trace(tem);
//						}
						if(tem==m) {
							dp[i+1][lps[m-1]]=max(dp[i][j]+1,dp[i+1][lps[m-1]]);
						} else
							dp[i+1][tem]=max(dp[i+1][tem],dp[i][j]);
					}
				} else {
					int tem=preco(j,s[i]);
					if(tem==m)
						dp[i+1][lps[m-1]]=max(dp[i][j]+1,dp[i+1][lps[m-1]]);
					else
						dp[i+1][tem]=max(dp[i+1][tem],dp[i][j]);
				}
			}
		}
	}
//	cout<<dp[1][1]<<endl;
//	cout<<dp[2][2]<<endl;
	int ans=0;
	for(int j=0; j<m; j++)
		ans=max(ans,dp[n][j]);
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
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}