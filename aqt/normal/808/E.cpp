
// Problem : E. Selling Souvenirs
// Contest : Codeforces - Educational Codeforces Round 21
// URL : https://codeforces.com/problemset/problem/808/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<long long> val[4];
long long dp[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		int w, c;
		cin >> w >> c;
		val[w].push_back(c);
	}
	for(int k = 1; k<=3; k++){
		if(val[k].empty()){
			continue;
		}
		sort(val[k].begin(), val[k].end(), greater<int>());
		//partial_sum(val[k].begin(), val[k].end(), val[k].begin());
	}
	int idx1 = 0, idx2 = 0;
	for(int i = 2; i<=M; i+=2){
		long long opt1 = 0, opt2 = 0;
		if(idx1+1 < val[1].size()){
			opt1 = val[1][idx1] + val[1][idx1+1];
		}
		else if(idx1 < val[1].size()){
			opt1 = val[1][idx1];
		}
		if(idx2 < val[2].size()){
			opt2 = val[2][idx2];
		}
		//cout << opt1 << " " << opt2 << endl;
		if(opt1 > opt2){
			idx1 += 2;
			dp[i] = dp[i-2] + opt1;
		}
		else{
			idx2++;
			dp[i] = dp[i-2] + opt2;
		}
	}
	idx1 = idx2 = 0;
	if(val[1].size()){
		dp[1] = val[1][idx1];
		idx1++;
	}
	for(int i = 3; i<=M; i+=2){
		long long opt1 = 0, opt2 = 0;
		if(idx1+1 < val[1].size()){
			opt1 = val[1][idx1] + val[1][idx1+1];
		}
		else if(idx1 < val[1].size()){
			opt1 = val[1][idx1];
		}
		if(idx2 < val[2].size()){
			opt2 = val[2][idx2];
		}
		//cout << opt1 << " " << opt2 << endl;
		if(opt1 > opt2){
			idx1 += 2;
			dp[i] = dp[i-2] + opt1;
		}
		else{
			idx2++;
			dp[i] = dp[i-2] + opt2;
		}
	}
	for(int i = 1; i<=M; i++){
		dp[i] = max(dp[i-1], dp[i]);
		//cout << dp[i] << "\n";
	}
	long long ans = 0, tot = 0;
	for(int i = 0; i<=val[3].size(); i++){
		long long lim = M-3*i;
		if(lim < 0){
			break;
		}
		//cout << tot << " " << dp[lim] << " " << lim << endl;
		ans = max(ans, tot + dp[lim]);
		if(i != val[3].size()){
			tot += val[3][i];
		}
	}
	cout << ans;
}