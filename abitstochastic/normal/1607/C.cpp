#include<bits/stdc++.h>
using namespace std;

int A[200003] , N , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		sort(A + 1 , A + N + 1); int mx = A[1];
		for(int i = 2 ; i <= N ; ++i) mx = max(mx , A[i] - A[i - 1]);
		cout << mx << endl;
	}
	return 0;
}