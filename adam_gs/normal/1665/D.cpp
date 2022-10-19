#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	ll x=0;
	rep(i, 30) {
		ll a=(1<<i)-x, b=(1<<(i+1))+a;
		cout << "? " << a << " " << b << endl;
		ll p;
		cin >> p;
		if(p%(1<<(i+1))==0) x+=1<<i;
	}
	cout << "! " << x << endl;
}
int main() {
	int _;
	cin >> _;
	while(_--) solve();
}