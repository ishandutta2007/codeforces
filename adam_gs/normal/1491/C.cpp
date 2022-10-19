#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n;
	cin >> n;
	ll T[n], ile[n], ans=0;
	rep(i, n) cin >> T[i];
	rep(i, n) ile[i]=0;
	rep(i, n) {
		while(ile[i]) {
			if(T[i]==1) {
				if(i<n-1) ile[i+1]+=ile[i];
				break;
			}
			--ile[i];
			if(i+T[i]<n) ++ile[i+T[i]];
			--T[i];
		}
		if(T[i]>=n-i) {
			if(i!=n-1) {
				ll p=n-i-1;
				ans+=T[i]-p;
				T[i]=p;
			} else {
				ans+=T[i]-1;
				T[i]=1;
			}
		}
		while(T[i]>1) {
			++ile[i+T[i]];
			--T[i];
			++ans;
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//t=1;
	while(t--) solve();
}