
// Problem : A. Three Strings
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/0
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		string a, b, c;
		cin >> a >> b >> c;
		bool t = 1;
		for(int i = 0; i<a.size(); i++){
			if(a[i] == c[i] || c[i] == b[i]){
				
			}
			else{
				t = 0;
			}
		}
		if(!t){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}