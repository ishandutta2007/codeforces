#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		ll a, b, c, m;
		cin >> a >> b >> c >> m;
		ll l = max(max({a, b, c}) - 1 - (a + b + c - max({a, b, c})), 0ll);
		ll r = a - 1 + b - 1 + c - 1;
		cout << ((l <= m && m <= r) ? "YES" : "NO") << endl;
	}
	return 0;
}