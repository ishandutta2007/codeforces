
// Problem : Three Indices
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1380/problem/A
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
		int N;
		cin >> N;
		vector<int> v;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}
		bool good = 0;
		for(int i = 1; i<N-1; i++){
			if(v[i] >= v[i-1] && v[i] >= v[i+1]){
				good = 1;
				cout << "YES\n";
				cout << i << " " << i+1 << " " << i+2 << "\n";
				break;
			}
		}
		if(!good){
			cout << "NO\n";
		}
	}
}