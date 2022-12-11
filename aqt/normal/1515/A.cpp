
// Problem : A. Phoenix and Gold
// Contest : Codeforces - Codeforces Global Round 14
// URL : https://codeforces.com/contest/1515/problem/A
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
		int tot = 0;
		vector<int> vec;
		while(N--){
			int n;
			cin >> n;
			vec.push_back(n);
			tot += n;
		}
		if(K == tot){
			cout << "NO\n";
			continue;
		}
		sort(vec.begin(), vec.end());
		int pre = 0;
		for(int i = 0; i < vec.size(); i++){
			pre += vec[i];
			if(pre == K){
				swap(vec[i], vec[i+1]);
				break;
			}
		}
		cout << "YES\n";
		for(int n : vec){
			cout << n << " ";
		}
		cout << "\n";
	}
}