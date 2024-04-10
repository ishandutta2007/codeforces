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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ld EPS = 1e-7;

ll a[N], b[N], c[N], d[N];
ll mx[N];
int Main(){
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= m; i++) cin >> c[i] >> d[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cout << i << " " << j << '\n';
			if(a[i] > c[j]) continue;
			if(b[i] > d[j]) continue;
			//cout << "!\n";
			mx[c[j] - a[i]] = max(mx[c[j] - a[i]], d[j] - b[i] + 1);
		}
	}
	ll ans = N;
	ll cn = 0;
	for(int i = N - 1; i >= 0; i--){
		cn = max(cn, mx[i]);
		ans = min(ans, i + cn);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Main();
	return 0;
}