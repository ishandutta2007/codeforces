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

ll a[3];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> a[0] >> a[1] >> a[2];
		sort(a,a + 3);
		reverse(a,a  +3);
		ll ans = 0;
		for(int i = 0; i < 3; i++){
			if(a[i]) a[i] --, ans ++;
		}
		if(a[0] > 0 && a[1] > 0) a[1] --, a[0] --, ans ++;
		if(a[0] > 0 && a[2] > 0) a[2] --, a[0] --, ans ++;
		if(a[1] > 0 && a[2] > 0) a[2] --, a[1] --, ans ++;
		if(a[0] > 0 && a[1] > 0 && a[2] > 0) ans ++; 
		cout << ans << '\n';
	}
	return 0;
}