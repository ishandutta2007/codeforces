#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr make_pair
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll T[n], ans=0, ile[60], pot[60];
		pot[0]=1;
		rep(i, 60) ile[i]=0;
		rep(i, 59) pot[i+1]=pot[i]*2%MOD;
		rep(i, n) {
			cin >> T[i];
			ll p=T[i];
			for(int j=0; p; ++j) {
				ile[j]+=p%2;
				p/=2;
			}
		}
		rep(i, n) {
			ll l=0, p=0;
			rep(j, 60) {
				if(T[i]%2) {
					p+=pot[j]*n%MOD;
					l+=ile[j]*pot[j]%MOD;
				} else p+=ile[j]*pot[j]%MOD;
				p%=MOD;
				l%=MOD;
				T[i]/=2;
			}
			ans+=p*l%MOD;
			ans%=MOD;
		}
		cout << ans << '\n';
	}
}