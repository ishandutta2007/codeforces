
// Problem : D. Field expansion
// Contest : Codeforces - Playrix Codescapes Cup (Codeforces Round #413, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/799/problem/D
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long A, B, H, W, N;
int cntr = 0;
vector<int> v;

int solve(long long H, long long W){
	int ret = 50;
	for(int n = 0; n<min(22, (int) (v.size()+1)); n++){
		for(int m = 0; m<1<<n; m++){
			long long tempA = H, tempB = W;
			for(int k = 0; k<n; k++){
				if(m>>k&1){
					tempA *= v[k];
					tempA = min(tempA, A);
				}
				else{
					tempB *= v[k];
					tempB = min(tempB, B);
				}
			}
			int cnt = 0;
			//cout << tempA << " " << tempB << "\n";
			if(tempA < A){
				cnt += 32-__builtin_clz((A+tempA-1)/tempA-1);
			}
			if(tempB < B){
				cnt += 32-__builtin_clz((B+tempB-1)/tempB-1);
			}
			if(cnt <= cntr){
				ret = min(n+cnt, ret);
			}
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B >> H >> W >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		if(n == 2){
			cntr++;
		}
		else{
			v.push_back(n);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	int ans = solve(H, W);
	ans = min(ans, solve(W, H));
	if(ans == 50){
		ans = -1;
	}
	cout << ans << "\n";
}