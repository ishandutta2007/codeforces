/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pii;

const long long N = 100005;

long long n, k;
long long dp[N][2];
vector<pii> g[N];

void calc_0(long long at, long long par){
	vector<long long>son;
	for(auto u : g[at]){
		if(u.first == par) continue;
		son.push_back( dp[u.first][0] + u.second );
	}
	sort(son.begin(), son.end());
	reverse(son.begin(), son.end());
	for(long long i = 0; i < min((long long)(son.size()), k - 1); ++i){
		dp[at][0] += son[i];
	}
}

void calc_1(long long at, long long par){
	vector<long long>son;
	for(auto u : g[at]){
		if(u.first == par) continue;
		son.push_back( dp[u.first][0]  + u.second);
	}
	sort(son.begin(), son.end());
	reverse(son.begin(), son.end());
	multiset<long long>ms;
	long long sum = 0;
	for(long long i = 0; i < min((long long)(son.size()), k); ++i){
		ms.insert(son[i]);
		if(i != k-1) sum += son[i];
	}
	for(auto u : g[at]){
		if(u.first == par) continue;

		auto it = ms.find(dp[u.first][0] + u.second);
		if(it == ms.end()){
			dp[at][1] = max(dp[at][1], sum + u.second + dp[u.first][1]);
		}
		else{
			sum -= dp[u.first][0] + u.second;
			if(ms.size() == k) sum += *(ms.begin());
			dp[at][1] = max(dp[at][1], sum + u.second + dp[u.first][1]);
			if(ms.size() == k) sum -= *(ms.begin());
			sum += dp[u.first][0] + u.second;
		}
	}
}

void dfs(long long at, long long par){
	/*

	dp[at][0] = come back to at after finishing
	dp[at][1] = finish at subtree of at, no coming back

	*/

	for(auto u : g[at]){
		if(u.first == par) continue;
		dfs(u.first, at);
	}

	calc_0(at, par);
	calc_1(at, par);

	// cout << "# " << at << ' ' << dp[at][0] << ' ' << dp[at][1] << endl;
}

int main(){
	long long x, y, c;
	scanf("%lld %lld", &n, &k);
	for(long long i = 1; i < n; ++i){
		scanf("%lld %lld %lld", &x, &y, &c);
		g[x].push_back({y, c});
		g[y].push_back({x, c});
	}
	dfs(0, 0);
	cout << dp[0][1] << endl;
	return 0;
}