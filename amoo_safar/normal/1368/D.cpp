// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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
ll b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int cnt = 0;
	for(int l = 0; l < 22; l++){
		cnt = 0;
		for(int j = 0; j < n; j ++) cnt += (a[j] >> l & 1);
		for(int j = 0; j < cnt; j++) b[j] |= (1 << l);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) ans += b[i] * b[i];
	cout << ans << '\n';
	return 0;
}