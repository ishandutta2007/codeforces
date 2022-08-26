#include<bits/stdc++.h>
using namespace std;

int main(){
	map < int , int > x; int T;
	for(cin >> T ; T ; --T){
		x.clear(); int N; cin >> N;
		for(int i = 1 ; i <= N ; ++i){
			int v; cin >> v; ++x[abs(v)];
		}
		int sum = 0;
		for(auto t : x) sum += min(t.second , 2 - (t.first == 0));
		cout << sum << endl;
	}
	return 0;
}