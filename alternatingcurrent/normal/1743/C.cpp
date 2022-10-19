#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	static int has[200200];
	rep(i, n)
		cin >> has[i];
	
	int ans = 0;
	for(int l = 0; l < n; ){
		while(l < n && s[l] == '0') ++l;
		if(l >= n) break;
		int r = l;
		int mn = l ? has[l-1] : 0x3f3f3f3f;
		while(r < n && s[r] == '1') ans += has[r], mn = min(mn, has[r]), ++r;
//		cout << l << " " << r << " " << ans << endl;
		if(l) ans += has[l-1] - mn;
		l = r;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	rep(i, T)
		solve();
	
	return 0;
}