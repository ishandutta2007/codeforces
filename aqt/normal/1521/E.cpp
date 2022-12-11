
// Problem : E. Nastia and a Beautiful Matrix
// Contest : Codeforces - Codeforces Round #720 (Div. 2)
// URL : https://codeforces.com/contest/1521/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
		vector<pair<int, int>> fre;
		for(int i = 0; i < K; i++){
			int n;
			cin >> n;
			fre.emplace_back(n, i+1);
		}
		sort(fre.begin(), fre.end(), greater<pair<int, int>>());
		fre.emplace_back(1000000, 0);
		vector<vector<int>> out;
		int l = 1, r = sqrt(4 * N);
		while(l <= r){
			int mid = l + r >> 1;
			vector<vector<int>> arr(mid, vector<int>(mid));
			int idx = 0, tot = fre[0].first;
			auto func = [&](int a ,int b) {
				for(int i = a ;i < mid; i += 2){
					for(int j = b; j < mid; j += 2){
						arr[i][j] = fre[idx].second;
						tot--;
						while(tot == 0){
							idx++;
							tot = fre[idx].first;
						}
					}
				}
			};
			func(0, 1);
			func(0, 0);
			func(1, 0);
			bool good = (idx == K);
			for(int i = 1; i < mid; i++){
				for(int j = 1; j < mid; j++){
					if(arr[i-1][j-1] && arr[i][j] && arr[i-1][j-1] == arr[i][j]){
						good = 0;
					}
					if(arr[i-1][j] && arr[i][j-1] && arr[i-1][j] == arr[i][j-1]){
						good = 0;
					}
				}
			}
			/*
			cout << "test: " << mid << "\n";
			for(int i = 0; i < mid; i++){
				for(int j = 0; j < mid; j++){
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
			*/
			if(good){
				r = mid - 1;
				out = arr;
			}
			else{
				l = mid + 1;
			}
		}
		cout << out.size() << "\n";
		for(auto v : out){
			for(int n : v){
				cout << n << " ";
			}
			cout << "\n";
		}
	}	
}