
// Problem : F. Jog Around The Graph
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct line{
	mutable long long m, b, p;
	bool operator < (const line &l) const{
		return m < l.m;
	}
	bool operator < (long long x) const {
		return p < x;
	}
};
 
struct LineContainer : multiset<line, less<>>{
	const long long inf = LLONG_MAX/2;
	bool inter(iterator x, iterator y){
		if(y == end()){
			x->p = inf;
			return 0;
		}
		if(x->m == y->m){
			x->p = (x->b <= y->b ? -inf : inf);
		}
		else{
			long long db = (y->b - x->b), dm = (x->m - y->m);
			x->p = db/dm - ((db^dm) < 0 && db%dm);
		}
		return x->p >= y->p;
	}
	void add(long long m, long long b){
		auto z = insert({m, b, 0}), y = z++, x = y;
		while(inter(y, z)){
			z = erase(z);
		}
		if(x != begin() && inter(--x, y)){
			inter(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p){
			inter(x, erase(y));
		}
	}
	long long query(long long n){
		auto l = *lower_bound(n);
		return l.m * n + l.b;
	}
};

int N, M, K;
long long dp[2005][2005];
vector<pair<int, int>> graph[2005];
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	memset(dp, -1, sizeof dp);
	dp[0][1] = 0;
	for(int k = 0; k<=N; k++){
		for(int n = 1; n<=N; n++){
			if(dp[k][n]+1){
				for(auto e : graph[n]){
					dp[k+1][e.first] = max(dp[k+1][e.first], dp[k][n] + e.second);
				}
			}
		}
	}
	LineContainer lc;
	long long ans = 0;
	for(int k = 0; k<=min(N, K); k++){
		long long bst = 0;
		for(int n = 1; n<=N; n++){
			for(auto e : graph[n]){
				if(dp[k][n]+1){
					lc.add(e.second, dp[k][n] - 1LL*e.second*k);
					bst = max(dp[k][n], bst);
				}
			}
		}
		ans += bst;
		//cout << bst << "\n";
		ans %= MOD;
	}
	line lst = {0, 0, min(N, K)};
	for(auto p : lc){
		//cout << "x: " << p.p << "\n";
		long long l = p.p;
		l = max(l, 1LL*min(N, K));
		l = min(l, 1LL*K);
		//cout << p.p << "\n";
		//cout << l << " " << lst.p << "\n";
		//cout << (l - lst.p) * (lst.p + l + 1) / 2 << " " << p.m << "\n";
		assert(l >= lst.p);
		ans += ((l - lst.p) * (lst.p + l + 1) / 2) % MOD * p.m % MOD;
		ans += (l - lst.p) * p.b % MOD;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		lst = {p.m, p.b, l};
	}
	/*
	auto ln = *(--lc.end());
	long long l = K;
	ans += ((l - lst.p) * (lst.p + l + 1) / 2) * lst.m % MOD;
	ans += (l - lst.p) * lst.b % MOD;
	ans %= MOD;	
	*/
	cout << ans;
}