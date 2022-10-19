#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;	
		cin >> n;
		vector<pair<int,int>>ans;
		int p=n;
		for(int i=n-1; i>2; --i) {
			int s=sqrt(p);
			if(i==s) {
				ans.push_back(pr(n, i));
				p=(p+i-1)/i;
			}
			ans.push_back(pr(i, n));
		}
		while(p>1) {
			p=(p+1)/2;
			ans.push_back(pr(n, 2));
		}
		cout << ans.size() << '\n';
		for(auto i : ans) cout << i.first << " " << i.second << '\n';
	}
}