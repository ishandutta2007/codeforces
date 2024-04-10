
// Problem : C. Discrete Acceleration
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, L;
int arr[100005];

long double solve(long double d){
	long double u = 0;
	for(int i = 1; i<=N+1; i++){
		if(d <= arr[i]){
			u += (long double) (1.0)*(d - arr[i-1])/i;
			break;
		}
		else{
			u += (long double) (1.0)*(arr[i] - arr[i-1])/i;
		}
	}
	long double v = 0;
	for(int i = N; i>=0; i--){
		if(d >= arr[i]){
			v += (long double) (1.0)*(arr[i+1] - d)/(N+1-i);
			break;
		}
		else{
			v += (long double) (1.0)*(arr[i+1] - arr[i])/(N+1-i);
		}
	}
	return max(u, v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> L;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		arr[N+1] = L;
		long double l = 0, r = L, ans = 1e9;
		for(int it = 100; it; it--){
			long double lm = solve((2*l+r)/3);
			long double rm = solve((l+2*r)/3);
			if(lm < rm){
				r = (l+2*r)/3;
				ans = min(ans, lm);
			}
			else{
				l = (2*l+r)/3;
				ans = min(ans, rm);
			}
			//cout << l << " " << r << " " << lm << " " << rm << "\n";
		}
		cout << setprecision(14) << ans << "\n";
	}
}