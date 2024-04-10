#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
ll ile[LIM], ans[LIM];
void solve() {
	ll n;
	cin >> n;
	rep(i, n+1) {
		ile[i]=0;
		ans[i]=-1;
	}
	ans[0]=0;
	rep(i, n) {
		ll a;
		cin >> a;
		++ile[a];
	}
	priority_queue<ll>q;
	for(ll i=1; i<=n; ++i) {
		rep(j, ile[i-1]) q.push(i-1);
		if(q.empty()) break;
		ll p=q.top(); q.pop();
		ans[i]=ans[i-1]+i-p-1;
	}
	rep(i, n+1) {
		if(ans[i]!=-1) ans[i]+=ile[i];
		cout << ans[i] << " ";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}