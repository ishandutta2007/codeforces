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

ll cnt[100];
ll a[N], wh;
bool CMP(ll i, ll j){
	return (i&wh) > (j&wh);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < 40; j++) if(a[i] >> j & 1) cnt[j] ++;
	}
	for(int j = 0; j < 40; j++) if(cnt[j] < 2) wh |= (1ll << j);
	sort(a, a + n, CMP);
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}