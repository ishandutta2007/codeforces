
// Problem : A. Perfectly Imperfect Array
// Contest : Codeforces - Codeforces Round #716 (Div. 2)
// URL : https://codeforces.com/contest/1514/problem/A
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
		bool good = 0;
		int N;
		cin >> N;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			int s = sqrt(n);
			if(s*s != n){
				good = 1;
			}
		}
		cout << (good ? "YES" : "NO") << "\n";
	}
}