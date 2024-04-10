
// Problem : B. MEXor Mixup
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int pre[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int i = 1; i <= 300000; i++){
		pre[i] = (pre[i-1]^i);
	}
	while(T--){
		int A, B;
		cin >> A >> B;
		int X = pre[A-1];
		int K = B ^ X;
		if(K == 0){
			cout << A << "\n";
		}
		else if(K == A){
			cout << A + 2 << "\n";
		}
		else{
			cout << A+1 << "\n";
		}
	}
}