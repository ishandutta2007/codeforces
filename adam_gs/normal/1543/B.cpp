#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	ll n;
	cin >> n;
	ll sum=0;
	rep(i, n) {
		ll a;
		cin >> a;
		sum+=a;
	}
	sum%=n;
	ll zero=n-sum;
	cout << zero*sum << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}