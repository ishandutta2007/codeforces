
// Problem : A. Avoiding Zero
// Contest : Codeforces - Codeforces Global Round 11
// URL : https://codeforces.com/contest/1427/problem/A
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
		int N;
		cin >> N;
		vector<int> v;
		int tot = 0;
		for(int i = 0; i<N; i++){
			int n;
			cin >> n;
			v.push_back(n);
			tot += n;
		}
		sort(v.begin(), v.end());
		if(tot == 0){
			cout << "NO\n";
		}
		else {
			if(tot > 0){
				reverse(v.begin(), v.end());
			}
			cout << "YES\n";
			for(int n : v){
				cout << n << " ";
			}
			cout << "\n";
		}
	}
}