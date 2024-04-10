
// Problem : A. Bad Ugly Numbers
// Contest : Codeforces Global Round 7
// URL : https://codeforces.com/contest/1326/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--){
		int n;
		cin >> n;
		if(n == 1){
			cout << -1 << "\n";
		}
		else{
			for(int i = 1; i<n; i++){
				cout << 5;
			}
			cout << 8 << "\n";
		}
	}
}