
// Problem : A. Odd Selection
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int A = 0, B = 0;
		int N, K;
		cin >> N >> K;
		while(N--){
			int n;
			cin >> n;
			n &= 1;
			if(n == 1){
				A++;
			}
			else{
				B++;
			}
		}
		bool b = 0;
		for(int k = 1; k<=K; k+=2){
			if(k > A){
				break;
			}
			if(K-k <= B){
				b = 1;
				break;
			}
		}
		if(b){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}