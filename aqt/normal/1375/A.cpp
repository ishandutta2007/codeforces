
// Problem : A. Sign Flipping
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/A
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
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			if(i%2 == 0){
				cout << abs(n) << " ";
			}
			else{
				cout << -abs(n) << " ";
			}
		}
		cout << "\n";
	}
}