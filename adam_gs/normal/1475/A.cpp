#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		bool ans=false;
		while(n>1) {
			if(n%2==1) {
				ans=true;
			}
			n/=2;
		}
		cout << (ans?"YES":"NO") << '\n';
	}
}