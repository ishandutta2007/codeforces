#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=1e5+7;
int T[LIM], P[LIM], dp[LIM][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t;
	cin >> s >> t;
	if(t.size()>s.size()) {
		cout << 0 << '\n';
		return 0;
	}
	rep(i, t.size()) {
		T[i]=1;
		rep(j, t.size()-i-1) if(t[j]!=t[i+j+1]) T[i]=0;
	}
	for(int i=t.size()-1; i<s.size(); ++i) {
		P[i+1]=1;
		rep(j, t.size()) if(s[i-j]!=t[t.size()-j-1] && s[i-j]!='?') P[i+1]=0;
	}
	for(int i=t.size(); i<=s.size(); ++i) {
		dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
		if(!P[i]) continue;
		dp[i][1]=max(dp[i][1], max(dp[i-t.size()][0], dp[i-t.size()][1])+1);
		rep(j, t.size()) if(T[j] && P[i-j-1]) dp[i][1]=max(dp[i][1], dp[i-j-1][1]+1);
	}
	cout << max(dp[s.size()][0], dp[s.size()][1]) << '\n';
}