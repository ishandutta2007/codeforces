
// Problem : E1. Reading Books (easy version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/E1
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<long long> typ[4];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		int v, a, b;
		cin >> v >> a >> b;
		int t = 2*a+b;
		typ[t].push_back(v);
	}
	for(int k = 1; k<4; k++){
		typ[k].push_back(0);
		sort(typ[k].begin(), typ[k].end());
		partial_sum(typ[k].begin(), typ[k].end(), typ[k].begin());
	}
	long long ans = LLONG_MAX/2;
	for(int k = 0; k<=K; k++){
		if(k+1 <= typ[3].size() && K-k+1 <= min(typ[1].size(), typ[2].size())){
			ans = min(ans, typ[3][k] + typ[2][K-k] + typ[1][K-k]);
		}
	}
	if(ans == LLONG_MAX/2){
		ans = -1;
	}
	cout << ans;
}