#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7;
ll ile[32];
void solve() {
	rep(i, 32) ile[i]=0;
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		++ile[lg(a)];
	}
	ll ans=0;
	rep(i, 32) ans+=ile[i]*(ile[i]-1)/2;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}