#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); int T;
	for(cin >> T ; T ; --T){
		int N , A , B; cin >> N >> A >> B;
		if(A + B <= N - 2 && A - B <= 1 && B - A <= 1){
			vector < int > pot; int L = 1 , R = N; bool flg = A < B;
			if(flg) pot.push_back(R--); else pot.push_back(L++);
			while(flg ? B : A){if(flg){pot.push_back(L++); --B;}else{pot.push_back(R--); --A;} flg ^= 1;}
			if(!flg) for(int i = L ; i <= R ; ++i) pot.push_back(i); else for(int i = R ; i >= L ; --i) pot.push_back(i);
			for(auto t : pot) cout << t << ' ';
			cout << endl;
		}else cout << -1 << endl;
	}
	return 0;
}