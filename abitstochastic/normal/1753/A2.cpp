#include<bits/stdc++.h>
using namespace std;

int N , A[200003] , T; bool flag[200003];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; int sum = 0; flag[N + 1] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; sum += A[i]; flag[i] = 0;}
		if(sum != 0){
			if(sum < 0){sum = -sum; for(int i = 1 ; i <= N ; ++i) A[i] = -A[i];}
			for(int i = 2 ; i <= N && sum ; ++i) if(A[i] == 1){flag[i] = 1; sum -= 2; ++i;}
			if(sum){cout << -1 << endl; continue;}
		}
		vector < pair < int , int > > pot;
		for(int i = 1 ; i <= N ; ++i) if(flag[i + 1] == 1){pot.push_back(make_pair(i , i + 1)); ++i;} else pot.push_back(make_pair(i , i));
		cout << pot.size() << '\n'; for(auto t : pot) cout << t.first << ' ' << t.second << '\n';
	}
	return 0;
}