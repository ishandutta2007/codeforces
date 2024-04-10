#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
ll pot(ll a,ll b){ll ans=1;while(b)if(b%2==1){ans=ans*a%MOD;--b;}else{a=a*a%MOD;b/=2;}return ans;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int p=0, s=0;
		while(n--) {
			int ans=1, a;
			cin >> a;
			s+=a;
			while(ans<=a && ans<=500000000) ans*=2;
			if(abs(a-ans/2)<abs(a-ans)) ans/=2;
			p+=abs(a-ans);
			cout << ans << " ";
		}
		cout << '\n';
	}
}