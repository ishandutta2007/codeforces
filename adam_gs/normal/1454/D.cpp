#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		long long x;
		cin >> x;
		long long p=x, i=2, k;
		int ans=1;
		while(i*i<=p) {
			int l=0;
			while(p%i==0) {
				p/=i;
				++l;
			}
			if(l>ans) {
				ans=l;
				k=i;
			}
			++i;
		}
		cout << ans << '\n';
		if(ans==1) cout << x; else {
			rep(i, ans-1) {
				cout << k << " ";
				x/=k;
			}
			cout << x;
		}
		cout << '\n';
	}
}