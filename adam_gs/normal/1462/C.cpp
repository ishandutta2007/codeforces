#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		long long x, li=0, k=1, i=9;
		cin >> x;
		if(x>45) {
			cout << "-1\n";
			continue;
		}
		while(x) {
			li+=k*min(i, x);
			x-=min(i, x);
			k*=10;
			--i;
		}
		cout << li << '\n';
	}
}