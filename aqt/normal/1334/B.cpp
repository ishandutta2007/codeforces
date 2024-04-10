
// Problem : B. Middle Class
// Contest : Educational Codeforces Round 85 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1334/problem/B
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
		int N;
		long long K;
		cin >> N >> K;
		vector<long long> v;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n; 
			v.push_back(n);
		}
		sort(v.begin(), v.end(), greater<int>());
		long long sum = 0;
		for(int i = 0; i<N; i++){
			sum += v[i];
			if(sum < K*(i+1)){
				cout << i << "\n";
				break;
			}
			else if(i == N-1){
				cout << N << "\n";
			}
		}
	}
}