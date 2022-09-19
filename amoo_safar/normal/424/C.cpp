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

multiset<pll> st;

ll ps[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ps[0] = 0;
	for(int i = 1; i < N; i++) ps[i] = ps[i - 1] ^ i;
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ans ^= ps[i - 1] * ((n / i) & 1);
		ans ^= ps[n % i];
	}
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		ans ^= v;
	}
	cout << ans << '\n';

	return 0;
}