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
		ll x;
		cin >> x;
		bool t=true;
		while(t) {
			t=false;
			ll p=x;
			while(p>0) {
				if(p%10>0 && x%(p%10)>0) t=true;
				p/=10;
			}
			++x;
		}
		cout << x-1 << '\n';
	}
}