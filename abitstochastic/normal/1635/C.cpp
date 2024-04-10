#include<bits/stdc++.h>
using namespace std;

int A[500003] , N , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; A[0] = -1e9; bool flg = 1; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; flg &= A[i] >= A[i - 1];}
		if(flg){puts("0"); continue;}
		if(A[N] >= A[N - 1] && A[N] >= 0){
			cout << N- 2 << endl;
			for(int i = 1 ; i <= N - 2 ; ++i) cout << i << ' ' << N - 1 << ' ' << N << endl;
		}else puts("-1");
	}
	return 0;
}