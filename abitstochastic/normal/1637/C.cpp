#include<bits/stdc++.h>
using namespace std;

#define int long long
int A[100003] , N , T;

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int ans = 0; bool flg = 0;
		for(int i = 2 ; i < N ; ++i){ans += (A[i] + 1) / 2; flg |= A[i] >= 2;}
		cout << (flg ? (N == 3 && A[2] % 2 ? -1 : ans) : -1) << endl;
	}
	return 0;
}