
// Problem : C. Felicity is Coming!
// Contest : Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/757/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> v[1000005];
map<vector<pair<int, int>>, int> mp;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i =1; i<=N; i++){
		map<int, int> f;
		int k;
		cin >> k;
		while(k--){
			int n;
			cin >> n;
			f[n]++;
		}
		for(auto p : f){
			v[p.first].emplace_back(p.second, i);
		}
	}
	for(int m = 1; m<=M; m++){
		mp[v[m]]++;
	}
	long long ans = 1;
	for(auto k : mp){
		int n = k.second;
		for(int i = 1; i<=n; i++){
			ans *= i;
			ans %= 1000000000+7;
		}
	}
	cout << ans;
}