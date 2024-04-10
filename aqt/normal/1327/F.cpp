
// Problem : F. AND Segments
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, M;
int lft[500005], rht[500005], x[500005];
const long long MOD = 998244353;
long long dp[500005];
int dif[500005];
int lim[500005];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> M;
	for(int i = 1; i<=M; i++){
		cin >> lft[i] >> rht[i] >> x[i];
	}
	long long ans = 1;
	for(int k = 0; k<K; k++){
		fill(dp, dp+2+N, 0);
		fill(dif, dif+2+N, 0);
		fill(lim, lim+2+N, 0);
		for(int i = 1; i<=M; i++){
			if((x[i]>>k)&1){
				dif[lft[i]]++;
				dif[rht[i]+1]--;
			}
			else{
				lim[rht[i]] = max(lft[i], lim[rht[i]]);
			}
		}
		dp[0] = 1;
		int lst = 0;
		for(int i = 1; i<=N+1; i++){
			dif[i] += dif[i-1];
			if(!dif[i]){
				if(lst){
					dp[i] = sub(dp[i-1], dp[lst-1]);
				}
				else{
					dp[i] = dp[i-1];
				}
			}
			if(i != N+1){
				dp[i] = add(dp[i], dp[i-1]);
			}
			lst = max(lst, lim[i]);
		}
		ans = mult(ans, dp[N+1]);
	}
	cout << ans << "\n";
}