#include<bits/stdc++.h>
using namespace std;

int main(){
	int N , K , T;
	for(cin >> T ; T ; --T){
		cin >> N >> K;
		if(K != N - 1 && K){
			cout << K << ' ' << N - 1 << endl << (N - 1 - K) << ' ' << 0 << endl;
			for(int i = 1 ; i < N / 2 ; ++i) if(i != K && i != N - 1 - K) cout << i << ' ' << N - 1 - i << endl;
		}else if(!K) for(int i = 0 ; i < N / 2 ; ++i) cout << i << ' ' << N - 1 - i << endl;
		else if(N == 4) cout << -1 << endl;
		else{
			cout << N - 1 << ' ' << N - 2 << endl << 1 << ' ' << 3 << endl << N - 4 << ' ' << 0 << endl;
			for(int i = 1 ; i < N / 2 ; ++i) if(i != 1 && i != 3) cout << i << ' ' << N - 1 - i << endl;
		}
	}
	return 0;
}