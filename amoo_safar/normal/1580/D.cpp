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
const int N = 4e3 + 10;
const ll Inf = 2242545357980376863LL;
// const ll Log = 30;
const int SQ = 400;

ll dp[N][N], fr = 2, a[N];
ll n, m;
void Solve(ll L, ll R, ll p){
	int mn = L;
	// cerr << "!! " << ' ' << L << ' ' << R << ' ' << p << '\n';
	for(int i = L; i <= R; i++){
		if(a[i]< a[mn]) mn = i;
	}
	int lc = mn == L ? 0 : fr ++;
	int rc = mn == R ? 0 : fr ++;
	if(lc)
		Solve(L, mn - 1, lc);
	if(rc)
		Solve(mn + 1, R, rc);
	for(int i = 0; i <= (mn - L); i++) for(int j = 0; j <= (R - mn); j++){
		for(int st = 0; st < 2; st ++){
			dp[p][i + j + st] = max(dp[p][i + j + st], dp[lc][i] + dp[rc][j] + st * (m+st) * a[mn] - 2ll * a[mn] * (i + st) * (j + st));
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// fill(dp[0], dp[0]);
	for(int i = 0; i < N; i++)
		fill(dp[i], dp[i] + N, -Inf);
	dp[0][0] = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Solve(1, n, 1);
	cout << dp[1][m] << '\n';
	return 0;
}