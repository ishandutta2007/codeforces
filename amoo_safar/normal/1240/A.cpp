#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1e9 + 7;
const int Maxn = 2e5 + 10;
const ll Inf = 1000000000000000LL;

ll a[Maxn], ps[Maxn];

int MAIN(){
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	ps[0] = 0;
	for(int i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + a[i - 1];
	}
	ll x, y, A, B;
	cin >> A >> x >> B >> y;
	if(A > B){
		swap(x, y);
		swap(A, B);
	}
	
	ll lc = x * y / __gcd(x, y);
	ll k;
	cin >> k;
	ll X, Y, Z, K;
	for(int i = 1; i <= n; i++){
		X = i/x;
		Y = i/y;
		Z = i/lc;
		X -= Z;
		Y -= Z;
		
		
		K = 0;
		K += ((ps[Z]) / 100) * (A+B);
		K += ((ps[Y + Z] - ps[Z]) / 100) * (B);
		K += ((ps[Y + Z + X] - ps[Y + Z]) / 100) * (A);
		//cerr << K << '\n';
		if(K >= k) return cout << i << '\n', 0;
	}
	cout << -1 << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}