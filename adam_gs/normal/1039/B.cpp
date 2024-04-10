#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
bool pytaj(ll a, ll b) {
	cout << a << " " << b << endl;
	string x;
	cin >> x;
	return x[0]=='Y';
}
ll losuj(ll a, ll b) {
	return rand()%(b-a+1)+a;
}
int main() {
	srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	ll n, k;
	cin >> n >> k;
	ll l=1, r=n;
	while(true) {
		if(r-l+1<=50) {
			ll a=losuj(l, r);
			if(pytaj(a, a)) return 0;
			l=max(1ll, l-k);
			r=min(n, r+k);
		}
		ll sr=(l+r)/2;
		if(pytaj(l, sr)) {
			r=min(sr+k, n);
			l=max(l-k, 1ll);
		} else {
			l=max(sr-k+1, 1ll);
			r=min(r+k, n);
		}
	}
}