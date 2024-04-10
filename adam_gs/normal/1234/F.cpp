#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int dp[1<<20], ile[20];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x;
	cin >> x;
	for(int r=1; r<=20 && r<=x.size(); ++r) {
		rep(i, 20) ile[i]=0;
		int zle=0, maska=0;
		rep(i, r) {
			++ile[x[i]-'a'];
			if(ile[x[i]-'a']==1) {
				maska+=1<<(x[i]-'a');
			} else if(ile[x[i]-'a']==2) {
				++zle;
			}
		}
		if(!zle) dp[maska]=__builtin_popcount(maska);
		for(int i=r; i<x.size(); ++i) {
			++ile[x[i]-'a'];
			if(ile[x[i]-'a']==1) {
				maska+=1<<(x[i]-'a');
			} else if(ile[x[i]-'a']==2) {
				++zle;
			}
			--ile[x[i-r]-'a'];
			if(ile[x[i-r]-'a']==0) {
				maska-=1<<(x[i-r]-'a');
			} else if(ile[x[i-r]-'a']==1) {
				--zle;
			}
			if(!zle) dp[maska]=__builtin_popcount(maska);
		}
	}
	rep(i, 1<<20) {
		rep(j, 20) if(!(i&(1<<j))) {
			dp[i|(1<<j)]=max(dp[i|(1<<j)], dp[i]);
		}
	}
	int ans=0;
	rep(i, 1<<20) {
		ans=max(ans, dp[i]+dp[(1<<20)-1-i]);
	}
	cout << ans << '\n';
}