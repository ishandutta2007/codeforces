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
	int T[n], odw[n], ans=n, l=0;
	rep(i, n) {
		cin >> T[i];
		odw[i]=0;
	}
	sort(T, T+n);
	rep(i, n) {
		if(T[i]<=n && !odw[T[i]-1]) {
			--ans;
			odw[T[i]-1]=1;
		} else {
			while(odw[l]) ++l;
			if((l+1)<=(T[i]-1)/2) odw[l]=1;
			else {
				cout << -1 << '\n';
				return;
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}