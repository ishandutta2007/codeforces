
// Problem : B. Xenia and Colorful Gems
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/contest/1336/problem/B
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
vector<long long> v[3];
int sz[3];

long long calc(long long a, long long b, long long c){
	return (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
}

long long solve(int k1, int k2, int k3){
	long long ret = LLONG_MAX;
	for(int i = 0; i<sz[k1]; i++){
		int idx1 = lower_bound(v[k2].begin(), v[k2].end(), v[k1][i]) - v[k2].begin();
		if(idx1 == sz[k2]){
			continue;
		}
		int idx2 = lower_bound(v[k3].begin(), v[k3].end(), (v[k2][idx1]+v[k1][i]+1)/2) - v[k3].begin();
		//cout << i << " " << idx1 << " " << idx2 << " " << (v[k2][idx1]+v[k1][i]+1)/2 << "\n";
		if(idx2 != sz[k3]){
			ret = min(ret, calc(v[k1][i], v[k2][idx1], v[k3][idx2]));
		}
		if(idx2){
			ret = min(ret, calc(v[k1][i], v[k2][idx1], v[k3][idx2-1]));
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		long long ans = LLONG_MAX;
		cin >> sz[0] >> sz[1] >> sz[2];
		for(int k = 0; k<3; k++){
			for(int i = 0; i<sz[k]; i++){
				long long n;
				cin >> n;
				v[k].push_back(n);
			}
			sort(v[k].begin(), v[k].end());
		}	
		ans = min(ans, solve(0, 1, 2));
		ans = min(ans, solve(0, 2, 1));
		ans = min(ans, solve(1, 0, 2));
		ans = min(ans, solve(1, 2, 0));
		ans = min(ans, solve(2, 0, 1));
		ans = min(ans, solve(2, 1, 0));
		v[0].clear();
		v[1].clear();
		v[2].clear();
		cout << ans << "\n";		
	}
}