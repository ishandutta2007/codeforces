#include<bits/stdc++.h>
using namespace std;

int A[100003];

int main(){
	int T; cin >> T;
	while(T--){
		int N; cin >> N; bool flg1 = 0 , flg0 = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; flg1 |= A[i] == 1; flg0 |= A[i] == 0;}
		sort(A + 1 , A + N + 1);
		if(!flg1){cout << "YES" << endl;}
		else{
			bool flg = 1;
			for(int i = 1 ; i < N ; ++i) flg &= A[i] != A[i + 1] - 1;
			cout << (flg ? "YES" : "NO") << endl;
		}
	}
	return 0;
}