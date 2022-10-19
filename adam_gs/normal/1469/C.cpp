#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {	
		ll n, k;
		cin >> n >> k;
		ll T[n];
		rep(i, n) cin >> T[i];
		ll mi=T[0], ma=T[0];
		bool ans=true;
		rep(i, n-1) {
			ll nmi=max(mi-k+1, T[i+1]), nma=min(ma+k-1, T[i+1]+k-1);
			mi=nmi; ma=nma;
			if((mi<=T[i+1] && T[i+1]<=ma) || (mi<=T[i+1]+k-1 && T[i+1]+k-1<=ma)); 
			else {
				ans=false;
				break;
			}
		}
		if((mi<=T[n-1] && T[n-1]<=ma)); else ans=false;
		if(ans) cout << "YES"; else cout << "NO";
		cout << '\n';
	}
}