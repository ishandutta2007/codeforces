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

// int dif[N], a[N];

int sum = 0;


ll a[N];
ll jm[N];
int Main(){
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	fill(jm, jm + n + 1, 0);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(jm[i] < a[i] - 1){
			ans += (a[i] - 1) - jm[i];
			jm[i] = a[i] - 1;
		}
		for(int j = i + 2; j <= min(i + a[i], n); j++) jm[j] ++;
		jm[i + 1] += (jm[i] - (a[i] - 1));
		jm[i + 1] = min(Inf, jm[i + 1]);
	}
	cout << ans << '\n';
	return 0;
	// cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}