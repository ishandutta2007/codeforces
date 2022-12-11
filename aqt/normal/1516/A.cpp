
// Problem : A. Tit for Tat
// Contest : Codeforces - Codeforces Round #717 (Div. 2)
// URL : https://codeforces.com/contest/1516/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> vec(N);
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			vec[i-1] = n;
		}
		for(int i = 1; i<N; i++){
			if(vec[i-1] <= K){
				K -= vec[i-1];
				vec[N-1] += vec[i-1];
				vec[i-1] = 0;
			}
			else{
				vec[i-1] -= K;
				vec[N-1] += K;
				K = 0;
			}
		}
		for(int n : vec){
			cout << n << " ";
		}
		cout << "\n";
	}
}