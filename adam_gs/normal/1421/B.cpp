#include <bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr make_pair
#define pb push_back
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string T[n];
		rep(i, n) cin >> T[i];
		int sum1=T[0][1]+T[1][0]-2*'0', sum2=T[n-1][n-2]+T[n-2][n-1]-2*'0';
		vector<pair<int,int>>ans;
		if(sum1<=sum2) {
			if(T[0][1]=='1') ans.pb(pr(1, 2));
			if(T[1][0]=='1') ans.pb(pr(2, 1));
			if(T[n-1][n-2]=='0') ans.pb(pr(n, n-1));
			if(T[n-2][n-1]=='0') ans.pb(pr(n-1, n));
		} else {
			if(T[0][1]=='0') ans.pb(pr(1, 2));
			if(T[1][0]=='0') ans.pb(pr(2, 1));
			if(T[n-1][n-2]=='1') ans.pb(pr(n, n-1));
			if(T[n-2][n-1]=='1') ans.pb(pr(n-1, n));			
		}
		cout << ans.size() << '\n';
		for(auto i : ans) cout << i.first << " " << i.second << '\n';
	}
}