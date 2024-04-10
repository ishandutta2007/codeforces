#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T;
	for(cin >> T ; T ; --T){
		int N , L , R , K; vector < int > A; cin >> N >> L >> R >> K;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; if(x >= L && x <= R) A.push_back(x);}
		sort(A.begin() , A.end() , [&](int p , int q){return p > q;}); int cnt = 0; while(A.size() && A.back() <= K){K -= A.back(); A.pop_back(); ++cnt;}
		cout << cnt << endl;
	}
	return 0;
}