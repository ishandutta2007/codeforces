#include <bits/stdc++.h>

using namespace std;

int N;
int dp[605][605];
int lft[605], rht[605];
char ans[1205];

int solve(int l, int r){
	if(l > r){
		return 1;
	}
	else if(dp[l][r]){
		return dp[l][r];
	}
	dp[l][r] = 2;
	for(int i = lft[l]; i<=rht[l]; i++){
		if(i&1){
			if(2*(r-l+1) > i && solve(l+1, i/2+l) == 1 && solve(i/2+l+1, r) == 1){
				return dp[l][r] = 1;
			}
		}
	}
	return 2;
}

void build(int l, int r, int idx){
	if(l > r){
		return;
	}
	ans[idx] = '(';
	for(int i = lft[l]; i<=rht[l]; i++){
		if(i&1){
			if(2*(r-l+1) > i && solve(l+1, i/2+l) == 1 && solve(i/2+l+1, r) == 1){
				ans[idx+i] = ')';
				build(l+1, i/2+l, idx+1);
				build(i/2+l+1, r, idx+i+1);
				return;
			}
		}
	}
	assert(0);
}

int main(){
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> lft[i] >> rht[i];
	}
	if(solve(1, N) == 2){
		cout << "IMPOSSIBLE";
	}
	else{
		build(1, N, 1);
		for(int i = 1; i<=2*N; i++){
			cout << ans[i];
		}
	}
}