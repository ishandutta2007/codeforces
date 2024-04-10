#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		for(int i = 2 ; i <= N + 1 ; ++i) cout << i << ' ';
		cout << endl;
	}
	return 0;
}