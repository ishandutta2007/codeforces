
// Problem : A. Wizard of Orz
// Contest : Codeforces - Codeforces Round #695 (Div. 2)
// URL : https://codeforces.com/contest/1467/problem/A
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
		vector<int> num;
		if(num.size() < N){
			num.push_back(9);
		}
		if(num.size() < N){
			num.push_back(8);
		}
		for(int i = 1; num.size() < N; i++){
			num.push_back((num.back()+1)%10);
		}
		for(int n : num){
			cout << n;
		}
		cout << "\n";
	}	
}