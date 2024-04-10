#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s, k;
		cin >> n >> s >> k;
		vector<int>ans;
		for(int i=n-1; i>=0; --i) {
			if(s[i]!=k[i]) {
				ans.pb(i+1);
				ans.pb(1);
				ans.pb(i+1);
			}
		}
		cout << ans.size() << " ";
		for(auto i : ans) cout << i << " ";
		cout << '\n';
	}
}