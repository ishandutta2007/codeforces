
// Problem : F. Swaps Again
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[505];
int brr[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		for(int j = 1; j<=N; j++){
			cin >> brr[j];
		}
		bool good = 1;
		if(N%2 == 1){
			good &= (arr[N/2+1] == brr[N/2+1]);
		}
		vector<pair<int, int>> v1, v2;
		for(int i = 1; i<=N/2; i++){
			if(arr[i] > arr[N-i+1]){
				swap(arr[i], arr[N-i+1]);
			}
			v1.emplace_back(arr[i], arr[N-i+1]);
			if(brr[i] > brr[N-i+1]){
				swap(brr[i], brr[N-i+1]);
			}
			v2.emplace_back(brr[i], brr[N-i+1]);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		good &= (v1 == v2);
		cout << (good ? "Yes" : "No") << "\n";
	}
}