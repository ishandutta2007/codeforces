#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7 , P = 998244353; int N , K , V[_] , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> V[i];
		bool flg = 1; for(int i = N ; i > N - K ; --i) if(V[i] >= 1) flg = 0;
		for(int i = 1 ; i <= N - K ; ++i) flg &= V[i] <= i - 1;
		if(!flg){cout << 0 << '\n';}
		else{
			int tms = 1; for(int i = 1 ; i <= K ; ++i) tms = 1ll * tms * i % P;
			for(int i = 1 ; i <= N - K ; ++i)
				if(V[i] == -1) tms = 1ll * tms * (i + K) % P;
				else if(V[i] == 0) tms = 1ll * tms * (K + 1) % P;
			cout << tms << '\n';
		}
	}
	return 0;
}