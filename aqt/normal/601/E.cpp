
// Problem : E. A Museum Robbery
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/contest/601/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q, W;
int v[30005], c[30005];
int lft[30005], rht[30005];
bool qu[30005];
const long long MOD = 1e9+7, BASE = 1e7+19;

void solve(int l, int r, vector<int> vec, vector<int> p){
	vector<int> dp(W+1);
	for(int w = 1; w<=W; w++){
		dp[w] = p[w];
	}
	int mid = l+r>>1;
	vector<int> lu, ru;
	for(int n : vec){
		//cout << lft[n] << " " << rht[n] << " " << n << "\n";
		if(lft[n] <= l && rht[n] >= r){
			for(int w = W; w>=c[n]; w--){
				dp[w] = max(dp[w], dp[w-c[n]] + v[n]);
			}
		}
		else if(rht[n] <= mid){
			lu.push_back(n);
		}
		else if(lft[n] > mid){
			ru.push_back(n);
		}
		else{
			lu.push_back(n);
			ru.push_back(n);
		}
	}
	if(l == r){
		//cout << l << " " << qu[l] << endl;
		if(qu[l]){
			long long ans = 0;
			for(int w = W; w; w--){
				ans *= BASE;
				ans += dp[w];
				ans %= MOD;
			}
			/*
			for(int w = 1; w<=W; w++){
				cout << dp[w] << " ";
			}
			cout << "\n";
			*/
			cout << ans << "\n";
		}
	}
	else{
		solve(l, mid, lu, dp);
		solve(mid+1, r, ru, dp);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> W;
	vector<int> it, cur(W+1);
	for(int i = 1; i<=N; i++){
		cin >> v[i] >> c[i];
		it.push_back(i);
	}
	cin >> Q;
	for(int i = 1; i<=N; i++){
		lft[i] = 1, rht[i] = Q;
	}
	for(int q = 1; q<=Q; q++){
		int cmd;
		cin >> cmd;
		if(cmd == 1){
			N++;
			cin >> v[N] >> c[N];
			lft[N] = q, rht[N] = Q;
			it.push_back(N);
		}
		else if(cmd == 2){
			int idx;
			cin >> idx;
			rht[idx] = q;
		}
		else{
			qu[q] = 1;
		}
	}
	solve(1, Q, it, cur);
}