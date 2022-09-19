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

ll a[N], b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll s = 0;
	for(int i = 0; i < m; i++){
		cin >> a[i];
		s += a[i];
	}
	if(s < n) return cout << "-1\n", 0;
	b[m] = n + 1;
	for(int i = m - 1; i >= 0; i--){
		b[i] = max(i + 1ll, b[i + 1] - a[i]);
		if(b[i] + a[i] - 1 > n) return cout << "-1\n", 0;
	}
	for(int i = 0; i < m; i++) cout << b[i] << ' ';
	return 0;
}