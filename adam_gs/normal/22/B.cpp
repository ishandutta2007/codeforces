#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=30, INF=1e9+7;
string T[LIM];
int dp[LIM][LIM];
int gora[LIM][LIM], dol[LIM][LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i];
		for(int j=m-1; j>=0; --j) if(T[i][j]=='0') dp[i][j]=dp[i][j+1]+1;
	}
	int ans=0;
	rep(j, m) {
		stack<pair<int,int>>q;
		q.push({-INF, -1});
		rep(i, n) {
			while(q.top().st>=dp[i][j]) q.pop();
			gora[i][j]=q.top().nd+1;
			q.push({dp[i][j], i});
		}
		while(!q.empty()) q.pop();
		q.push({-INF, n});
		for(int i=n-1; i>=0; --i) {
			while(q.top().st>=dp[i][j]) q.pop();
			dol[i][j]=q.top().nd-1;
			q.push({dp[i][j], i});
		}
		rep(i, n) if(T[i][j]=='0') ans=max(ans, 2*(dp[i][j]+dol[i][j]-gora[i][j]+1));
	}
	cout << ans << '\n';
}