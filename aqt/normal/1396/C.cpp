
// Problem : C. Monster Invaders
// Contest : Codeforces - Codeforces Round #666 (Div. 1)
// URL : https://codeforces.com/contest/1396/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long r1, r2, r3, d;
long long arr[1000005];
long long dp1[1000005];
long long dp2[1000005];
long long v1[1000005];
long long v2[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> r1 >> r2 >> r3 >> d;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
		v1[i] = min(r2, arr[i] * r1 + r1) + r1;
		v2[i] = arr[i] * r1 + r3;
	}	
	dp1[1] = min(v2[1], v1[1] + 2*d);
	for(int i = 2; i<=N; i++){
		long long opt1 = dp1[i-1] + min(v1[i] + 2*d, v2[i]) + d;
		long long opt2 = dp1[i-2] + min(v1[i-1], v2[i-1]) + min(v2[i], v1[i]) + 4 * d - (i == 2 ? d : 0);
		dp1[i] = min(opt1, opt2);
	}
	dp2[N] = min(2*d+v1[N], v2[N]);
	for(int i = N-1; i; i--){
		dp2[i] = 2*d + min(v1[i], v2[i]) + dp2[i+1];
	}
	long long ans = min(dp2[1], dp1[N]);
	//cout << dp2[1] << " " << dp1[N] << "\n";
	for(int i = 1; i<=N-1; i++){
		//cout << dp1[i] << " " << dp2[i+1] << "\n";
		ans = min(dp1[i] + dp2[i+1] + d, ans);
	}
	cout << ans << "\n";
}