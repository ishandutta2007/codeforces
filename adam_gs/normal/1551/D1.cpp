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
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if(n%2==1) {
		int ile=m/2;
		if((k-ile)%2==1 || k<ile) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
	} else if(m%2==1) {
		int p=n*m/2-k, ile=n/2;
		if((p-ile)%2==1 || p<ile) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
	} else {
		if(k%2==1) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}