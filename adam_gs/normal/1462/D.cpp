#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int T[n];
		rep(i, n) cin >> T[i];
		int s=0, ans=0;
		rep(i, n) {
			s+=T[i];
			int x=0, l=0;
			rep(j, n) {
				x+=T[j];
				if(x==s) {
					x=0;
					++l;
				}
				if(x>s) break;
			}
			if(x==0) ans=max(ans, l);
		}
		cout << n-ans << '\n';
	}
}