
// Problem : A. Cubes Sorting
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/A
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
		bool des = 1;
		int N;
		cin >> N;
		int lst = 0;
		cin >> lst;
		for(int i = 2; i<=N; i++){
			int c;
			cin >> c;
			if(c >= lst){
				des = 0;
			}
			lst = c;
		}
		cout << (des ? "NO" : "YES") << "\n";
	}
}