// vaziat meshki-ghermeze !
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

ll a[N];

int Main(){
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i += 2){
		ll s = 0;
		ll mn = 0;
		if(i + 1 < n)
			ans += min(a[i], a[i + 1]);
		for(int j = i + 1; j < n; j++){
			if(j % 2 == 0)
				s += a[j];
			else
				s -= a[j];

			mn = min(mn, s);
			if((j + 1 < n) && (j % 2 == 0)){
				ll rq = -mn;
				if(rq > a[i]) continue;
				if(rq + s > a[j + 1]) continue;
				ans += min(a[i] - rq, a[j + 1] - (rq + s)) + 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}