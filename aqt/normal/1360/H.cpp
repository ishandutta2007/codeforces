
// Problem : H. Binary Median
// Contest : Codeforces - Codeforces Round #644 (Div. 3)
// URL : https://codeforces.com/contest/1360/problem/H
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		long long K = ((1LL<<M)-N-1)/2;
		vector<long long > v;
		for(int i = 0; i<N; i++){
			string s;
			cin >> s;
			long long n = 0;
			for(int j = 0; j<M; j++){
				n *= 2;
				n += s[j] - '0';
				//n ^= 1;
			}
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		long long l = 0, r = (1LL<<M)-1, ans = 0;
		while(l <= r){
			long long mid = l+r>>1;
			long long cnt = mid;
			for(long long n : v){
				if(n <= mid){
					cnt--;
				}
			}
			if(cnt < K){
				l = mid + 1;
			}
			else{
				ans = mid;
				r = mid - 1;
			}
		}
		for(long long b = M-1; b>=0; b--){
			cout << ((ans>>b&1));
		}
		cout << "\n";
	}
}