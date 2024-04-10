#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
const int LIM=4e5+7;
ll ile[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, 2*n+7) ile[i]=0;
	map<int,int>mp;
	rep(i, n) {
		int a;
		cin >> a;
		++ile[a-i+n];
	}
	ll ans=0;
	rep(i, 2*n+7) {
		ans+=ile[i]*(ile[i]-1)/2;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}