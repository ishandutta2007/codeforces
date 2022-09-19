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
const int N = 32e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll C[N][N];
ll d = 1003;
ll ps[N][N];

ll x[N], y[N], b[N];

ll n, m, r;

int Get(int x1, int y1, int x2, int y2){
	if(x1 > x2 || y1 > y2) return 0;
	return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

ll mul(ll a, ll b){
	a %= Mod;
	b %= Mod;
	return (a * b) % Mod;
}

ll nv[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			C[i][j] = (j == 0 ? 1 : C[i - 1][j] + C[i - 1][j - 1]) % Mod;

	cin >> n >> m >> r;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> b[i];
		x[i] += d; y[i] += d;
		ps[x[i]][y[i]] ++;
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}
	ll ans = 0;
	ll al = C[n][m];
	for(int i = 0; i < n; i++){
		nv[i] = C[n - Get(x[i] - r, y[i] - r, x[i] + r, y[i] + r)][m]; 
		//cout << "! " << nv[i] << '\n';
	}

	ll sm;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sm = Get(x[i] - r, y[i] - r, x[i] + r, y[i] + r);
			sm += Get(x[j] - r, y[j] - r, x[j] + r, y[j] + r);
			sm -= Get(max(x[i], x[j]) - r, max(y[i], y[j]) - r, min(x[i], x[j]) + r, min(y[i], y[j]) + r);
			ans += mul(mul(b[i], b[j]), al - nv[i] - nv[j] + C[n - sm][m]);
			ans %= Mod;
		}
	}
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}