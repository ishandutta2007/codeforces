#include<bits/stdc++.h>
using namespace std;

int main(){
	int T; cin >> T;
	while(T--){
		int N , Sum = 0; cin >> N;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; Sum += x - 1;}
		cout << (Sum & 1 ? "errorgorn" : "maomao90") << endl;
	}
	return 0;
}