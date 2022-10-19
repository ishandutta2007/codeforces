#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
ll ile[5][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, 2) {
		ll x;
		cin >> x;
		rep(j, x) ++ile[(j+1)%5][i];
	}
	ll ans=0;
	rep(i, 5) ans+=ile[i][0]*(ile[(5-i)%5][1]);
	cout << ans << '\n';
}