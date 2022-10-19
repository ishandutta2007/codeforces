#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	ll T[n];
	rep(i, n) cin >> T[i];
	int l=0;
	rep(i, n) {
		while(T[i]<0) {
			while(l<i && T[l]<=0) ++l;
			if(T[l]<=0) break;
			ll p=min(T[l], -T[i]);
			T[l]-=p;
			T[i]+=p;
		}
	}
	ll ans=0;
	rep(i, n) if(T[i]>0) ans+=T[i];
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}