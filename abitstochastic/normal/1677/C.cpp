#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; int pot[_] , N , T , A[_] , B[_]; bool vis[_];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i) vis[i] = 0;
		for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = 1 ; i <= N ; ++i){cin >> B[i]; pot[A[i]] = B[i];}
		long long sum = 0 , pos = 0;
		for(int i = 1 ; i <= N ; ++i)
			if(!vis[i]){
				int len = 0 , cur = i;
				do{
					++len; vis[cur] = 1; cur = pot[cur];
				}while(cur != i);
				for(int j = 0 ; j < len / 2 ; ++j){
					sum += 2 * (N - pos) - 2 * (pos + 1);
					++pos;
				}
			}
		cout << sum << endl;
	}
	return 0;
}