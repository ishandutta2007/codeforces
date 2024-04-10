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
	int n, m;
	cin >> n >> m;
	int T[n][m], pocz[n], kon[n];
	rep(i, n) {
		rep(j, m) {
			cin >> T[i][j];
		}
		pocz[i]=0;
		kon[i]=m-1;
		sort(T[i], T[i]+m);
	}
	vector<int>ans[m];
	rep(j, m) {
		int mi=1000000007, p=-1;
		rep(i, n) {
			if(T[i][pocz[i]]<mi) {
				mi=T[i][pocz[i]];
				p=i;
			}
		}
		rep(i, n) {
			if(i==p) {
				ans[j].pb(T[i][pocz[i]]);
				++pocz[i];
			} else {
				ans[j].pb(T[i][kon[i]]);
				--kon[i];
			}
		}
	}
	rep(i, n) {
		rep(j, m) cout << ans[j][i] << " ";
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}