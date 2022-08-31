#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N; int S = 0;
		for(int i = 1 ; i <= N ; ++i){int V; cin >> V; S |= V;}
		cout << S << endl;
	}
	return 0;
}