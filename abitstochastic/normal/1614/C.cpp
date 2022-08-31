#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; int T , N , M;

int main(){
    ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; int v = 0; for(int j = 1 ; j <= M ; ++j){int x; cin >> x >> x >> x; v |= x;}
		int pw2 = 1; for(int j = 1 ; j < N ; ++j) pw2 = 2ll * pw2 % P;
		int sum = 0; for(int j = 0 ; j < 30 ; ++j) if(v >> j & 1) sum = (sum + (1ll << j) * pw2) % P;
		cout << sum << endl;
	}
	return 0;
}