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
typedef pair<int, int> pll;

const ll Mod = 1000000007LL;
const int N = 1e3 + 10;
const ll Inf = 1e18 + 10;
const ll Log = 30;

int n, m, lcp[N][N];
ll k;
str s;
vector< pll > V;

char Get(pll A, int x){
	if(x >= A.S - A.F) return '#';
	return s[A.F + x];
}
bool CMP(pll i, pll j){
	int lc = min(lcp[i.F][j.F], min(i.S - i.F, j.S - j.F));
	return Get(i, lc) > Get(j, lc);
}

pll W;
ll dp[N][N];
ll Check(){
	memset(dp, 0, sizeof dp);
	int ln = W.S - W.F;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		int lc = min(ln, lcp[W.F][i]);
		if(Get({i, n}, lc) > Get(W, lc)){
			for(int j = 0; j < n; j++){
				dp[i + lc + 1][j + 1] = min(Inf, dp[i + lc + 1][j + 1] + dp[i][j]);
			}
		}
		for(int j = 1; j <= n; j++){
			dp[i + 1][j] = min(Inf, dp[i + 1][j] + dp[i][j]);
		}
	}
	return dp[n][m];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> s; s += '#';

	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			V.pb({i, j});
		}
	}
	sort(all(V), CMP);
	/*
	for(auto x : V){
		cerr << x.F << " " <<x.S << " " << s.substr(x.F, x.S - x.F) << '\n';
	}
	cerr << CMP(V[V.size() - 3], V[V.size() - 2]) << '\n';
	*/
	int L = -1, R = V.size(), mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		W = V[mid];
		if(Check() < k) L = mid;
		else R = mid;
	}

	pll x = V[L];
	/*
	W = V[R];
	for(auto x : V){
		W = x;
		cerr << "!! " << Check() << '\n';
	}
	*/
	cout << s.substr(x.F, x.S - x.F) << '\n';
	return 0;
}