#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve(ll a, ll b) {
	for(ll i=1; i*b+a<=a*b-1; ++i) {
		if((a*b-1-i*b)%a==0) {
			cout << 2 << '\n' << i << " " << a << '\n' << (a*b-1-i*b)/a << " " << b << '\n';
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	for(ll i=2; i*i<=n; ++i) if(n%i==0) {
		ll p=1;
		while(n%i==0) {
			n/=i;
			p*=i;
		}
		cout << (n==1?"NO":"YES") << '\n';
		if(n==1) return 0;
		if(n>p) swap(n, p);
		solve(n, p);
		return 0;
	}
	cout << "NO\n";
}