#include<bits/stdc++.h>
using namespace std;

int A[500003] , N , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int cnt = 0;
		for(int i = 2 ; i < N ; ++i)
			if(A[i] > A[i - 1] && A[i] > A[i + 1]){
				++cnt; A[i + 1] = max(A[i] , A[i + 2]);
			}
		cout << cnt << endl;
		for(int i = 1 ; i <= N ; ++i) cout << A[i] << ' ';
		cout << endl;
	}
	return 0;
}