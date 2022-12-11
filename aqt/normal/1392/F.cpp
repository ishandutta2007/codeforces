
// Problem : F. Omkar and Landslide
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/problemset/problem/1392/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	long long S = 0;
	for(int i = 1; i<=N; i++){
		long long n;
		cin >> n;
		S += n;
	}
	if(N == 1){
		cout << S << "\n";
		return 0;
	}
	long long l = 0, r = 1000000000000LL;
	while(l <= r){
		long long mid = l+r>>1;
		long long k = 1LL*(2*mid+N-2)*(N-1)/2;
		if(S - k >= mid && S - k <= mid + N -1){
			vector<long long> v;
			for(long long n = mid; n <= mid + N - 2; n++){
				v.push_back(n);
			}
			v.push_back(S - k);
			sort(v.begin(), v.end());
			for(auto n : v){
				cout << n << " ";
			}
			return 0;
		}
		else if(S - k < mid){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	assert(0);
}