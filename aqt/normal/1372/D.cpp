
// Problem : D. Omkar and Circle
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long pre[2][400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		pre[i%2][i] = n;
		pre[1-i%2][i+N] = n;
	}
	for(int i = 1; i<=2*N; i++){
		pre[0][i] += pre[0][i-1];
		pre[1][i] += pre[1][i-1];
	}
	long long ans = 0;
	for(int i = 1+N; i<=2*N; i++){
		ans = max(ans, pre[i%2][i] - pre[i%2][i-N]);
	}
	cout << ans << "\n";
}