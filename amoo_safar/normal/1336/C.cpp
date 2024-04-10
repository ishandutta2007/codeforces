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

const ll Mod = 998244353;
const int N = 3e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str s, t;
ll n, m;
ll dp[N][N];


bool Can(char x, int i){
	if((i < 0) || (i >= s.size())) return false;
	if(i >= t.size()) return true;
	return (t[i] == x);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	n = s.size();
	m = t.size();

	for(int i = 0; i < n; i++) if(Can(s[0], i)) dp[i][i] = 2;
	for(int l = 0; l < n; l++){
		for(int i = 0; i < n; i++){
			int j = i + l;
			if(j >= n) continue;
			char c = s[l + 1];
			if(Can(c, i - 1)) (dp[i - 1][j] += dp[i][j]) %= Mod;
			if(Can(c, j + 1)) (dp[i][j + 1] += dp[i][j]) %= Mod;
		}
	}

	ll ans = 0;
	for(int i = m - 1; i <= n - 1; i++) ans += dp[0][i];
	cout << ans % Mod;
	return 0;
}