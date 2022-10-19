#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	ll n;
	cin >> n;
	if(n<5) {
		cout << "0\n";
		return;
	}
	ll p=1, k=n;
	while(p<k) {
		ll sr=(p+k+1)/2;
		if((sr*sr+1)/2>n) k=sr-1; else p=sr;
	}
	if(p%2==0) --p;
	cout << p/2 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}