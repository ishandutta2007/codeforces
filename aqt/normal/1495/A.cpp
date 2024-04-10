
// Problem : A. Diamond Miner
// Contest : Codeforces - Codeforces Round #706 (Div. 1)
// URL : https://codeforces.com/contest/1495/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		vector<long long> arr, brr;
		for(int i = 1; i<=2*N; i++){
			int x, y;
			cin >> x >> y;
			if(x == 0){
				brr.push_back(1LL*y*y);
			}
			else{
				arr.push_back(1LL*x*x);
			}
		}
		sort(brr.begin(), brr.end());
		sort(arr.begin(), arr.end());
		long double ans =0;
		for(int k = 0; k<N; k++){
			ans += sqrt(brr[k] + arr[k]);
		}
		cout << setprecision(14) << ans << "\n";
	}
}