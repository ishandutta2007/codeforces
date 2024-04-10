// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		vector<int> A(n, 0), C(34, 0);
		for(int i = 0; i < n; i++) cin >> A[i];
		for(auto x : A){
			for(int i = 31; i >= 0; i--)
				if(x >> i & 1){
					C[i] ++;
					break;
				}
			if(x == 0) C[33] ++;
		}
		ll ans = 0;
		for(auto x : C)
			ans += 1ll * x * (x - 1);
		cout << ans /2 << '\n';
	}
	return 0;
}