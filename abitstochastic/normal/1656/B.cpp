#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int N , K; cin >> N >> K; set < int > pot;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; pot.insert(x);}
		bool flg = 0;
		for(auto t : pot) flg |= pot.find(t + K) != pot.end();
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}