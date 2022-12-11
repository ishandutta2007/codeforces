
// Problem : C. Yet Another Array Restoration
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/C
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
		int N, A, B;
		cin >> N >> A >> B;
		int D = B-A;
		int F = 0;
		for(int i = 1; i<=D; i++){
			if(D%i == 0 && i < N){
				F = i;
			}
		}
		long long K = D/F;
		deque<int> dq;
		dq.push_back(A);
		while(dq.back() != B){
			dq.push_back(K+dq.back());
		}
		while(dq.size() < N && dq.front() > K){
			dq.push_front(dq.front()-K);
		}
		while(dq.size() < N){
			dq.push_back(K+dq.back());
		}
		for(int n : dq){
			cout << n << " ";
		}
		cout << "\n";
	}
}