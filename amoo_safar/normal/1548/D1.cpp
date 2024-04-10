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
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

pii po[N];

pii operator-(pii A, pii B){
	return pll(A.F - B.F, A.S - B.S);
}
ll Cross2(pii A, pii B){
	return (1ll*A.S * B.F - 1ll*A.F * B.S) & 1;
}

ll Cross4(pii A, pii B){
	return (1ll*A.S * B.F - 1ll*A.F * B.S) & 3;
}

ll Cross(pii A, pii B){
	return (1ll*A.S * B.F - 1ll*A.F * B.S);
}
int calc(pii A){
	if(A.F == 0) return abs(A.S);
	if(A.S == 0) return abs(A.F);
	int g = __gcd(abs(A.F), abs(A.S));
	return g;
}

ll cnt[4][4];
ll C3(ll n){
	return n * (n - 1) * (n - 2) / 6ll;
}

ll C2(ll n){
	return n * (n - 1) / 2ll;
}
ll C1(ll n){
	return n;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> po[i].F >> po[i].S;
		cnt[po[i].F % 4][po[i].S % 4] ++;
	}
	vector<pii> V;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			V.pb({i, j});
		}
	}
	ll ans = 0;
	for(auto [i1, j1] : V) for(auto [i2, j2] : V) for(auto [i3, j3] : V){
		// debug("A");
		// if(max({i1, j1, i3, j3, j2}) > 0) continue;
		// if(i2 != 2) continue;
		if(pii(i1, j1) < pii(i2, j2)) continue;
		if(pii(i2, j2) < pii(i3, j3)) continue;
		
		ll cn = 1;
		if(pii(i1, j1) == pii(i2, j2) && pii(i2, j2) == pii(i3, j3)) cn = C3(cnt[i1][j1]);
		else if(pii(i1, j1) == pii(i2, j2)) cn = 1ll * cnt[i3][j3] * C2(cnt[i1][j1]);
		else if(pii(i1, j1) == pii(i3, j3)) cn = 1ll * cnt[i2][j2] * C2(cnt[i3][j3]);
		else if(pii(i3, j3) == pii(i2, j2)) cn = 1ll * cnt[i1][j1] * C2(cnt[i3][j3]);
		else cn = 1ll * cnt[i1][j1] * cnt[i2][j2] * cnt[i3][j3];
		// debug(cn);

		pii a = pii(i1, j1);
		pii b = pii(i2, j2);
		pii c = pii(i3, j3);
		int A = Cross4(a, b) + Cross4(b, c) + Cross4(c, a);
		int on = calc(a- b) + calc(b - c) + calc(c - a);
		
		// debug(A);
		// debug(on);
		if(A % 2 == 1) continue;
		A /= 2;
		if(on % 2 == 1) continue;
		on /= 2;
		ll res = A - on + 1;
		res &= 1;
		// debug(res);
		if(res == 1){
			// debug(cn);
			ans += cn;
		}
	}
	cout << ans << '\n';
	// sort(all(V), [&](pii A, pii B){
	// 	pii va = po[A.F] - po[A.S];
	// 	pii vb = po[B.F] - po[B.S];
	// 	int fa = va < pii(0, 0);
	// 	int fb = vb < pii(0, 0);
	// 	if(fa != fb) return fa < fb;
	// 	return Cross(va, vb) < 0;
	// });
	// for(auto [i, j] : V){
	// 	pii vc = po[i] - po[j];
	// 	ll F = Cross(po[i], po[j]) % 4;
	// 	ll G = calc(vc);

	// }
	return 0;
}