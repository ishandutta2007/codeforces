#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N; int pre = -1; bool flg = 1;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; flg &= pre <= x; pre = x;}
		cout << (flg ? "NO" : "YES") << endl;
	}
	return 0;
}