#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, lp=0;
		cin >> n;
		string x, pom="2020";
		cin >> x;
		if(n<4) {
			cout << "NO\n";
			continue;
		}
		while(lp<4) if(x[lp]==pom[lp]) ++lp; else break;
		int lk=3, l=n-1;
		while(lk>=lp) {
			if(x[l]==pom[lk]) {
				--l;
				--lk;
			} else break;
		}
		if(lk<lp) cout << "YES\n"; else cout << "NO\n";
	}
}