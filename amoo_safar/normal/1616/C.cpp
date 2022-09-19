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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

ll a[N];
int Main(){
	map<ll, ll> mp;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n <= 2) return cout << 0 << '\n', 0;	
	ll res = n;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int ans = n;
			for(int k = 0; k < n; k++){
				ll d1 = k - i, x1 = a[k] - a[i];
				ll d2 = k - j, x2 = a[k] - a[j];
				if(d2 * x1 == x2 * d1) ans --;
			}
			res = min(res, (ll) ans);
		}
	}
	cout << res << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}