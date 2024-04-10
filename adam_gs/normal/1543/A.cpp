#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	ll a, b;
	cin >> a >> b;
	if(a==b) {
		cout << "0 0" << '\n';
		return;
	}
	if(b>a) swap(a, b);
	ll c=a-b;
	ll d=c-a;
	if(d<0) {
		d*=-1;
		d%=c;
		d*=-1;
		d+=c;
	} else {
		d%=c;
	}
	cout << c << " " << min(a%c, d) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}