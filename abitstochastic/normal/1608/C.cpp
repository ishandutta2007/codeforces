#include<bits/stdc++.h>
using namespace std;

int T , N , A[200003] , B[200003] , idA[200003] , idB[200003] , posA[200003] , posB[200003]; bool visA[200003] , visB[200003] , vis[200003];
queue < int > q; void push(int x){if(!vis[x]){vis[x] = 1; q.push(x);}}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[idA[i] = i];
		for(int i = 1 ; i <= N ; ++i) cin >> B[idB[i] = i];
		sort(idA + 1 , idA + N + 1 , [&](int p , int q){return A[p] < A[q];});
		sort(idB + 1 , idB + N + 1 , [&](int p , int q){return B[p] < B[q];});
		for(int i = 1 ; i <= N ; ++i){posA[idA[i]] = i; posB[idB[i]] = i;}
		for(int i = 1 ; i <= N ; ++i) visA[i] = visB[i] = vis[i] = 0;
		push(idA[N]); push(idB[N]);
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int p = posA[t] + 1; p <= N && !visA[p] ; visA[p++] = 1) push(idA[p]);
			for(int p = posB[t] + 1; p <= N && !visB[p] ; visB[p++] = 1) push(idB[p]);
		}
		for(int i = 1 ; i <= N ; ++i) cout << vis[i];
		cout << endl;
	}
	return 0;
}