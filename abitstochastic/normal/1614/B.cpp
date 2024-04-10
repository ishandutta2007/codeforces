#include<bits/stdc++.h>
using namespace std;

int N , A[200003] , id[200003] , P[200003];

int main(){
	ios::sync_with_stdio(0);
	int T;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; id[i] = i;}
		long long sum = 0; sort(id + 1 , id + N + 1 , [&](int p , int q){return A[p] > A[q];});
		for(int i = 1 ; i <= N ; ++i) sum += 2ll * abs(P[id[i]] = (i + 1) / 2 * (i & 1 ? 1 : -1)) * A[id[i]];
		cout << sum << endl;
		for(int i = 0 ; i <= N ; ++i) cout << P[i] << ' ';
		cout << endl;
	}
	return 0;
}