#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; int T , N , arr[_];

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		int sum = 0; vector < int > pot;
		for(int i = 1 ; i <= N ; ++i){sum += arr[i]; pot.push_back(sum);}
		while(pot.size() && pot.back() == 0) pot.pop_back();
		int mn = 1e9; for(auto t : pot) mn = min(mn , t);
		cout << (sum == 0 && mn > 0 ? "Yes" : "No") << endl;
	}
	
	return 0;
}