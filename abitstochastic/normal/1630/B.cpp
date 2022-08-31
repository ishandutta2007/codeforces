#include<bits/stdc++.h>
using namespace std;

int T , K , N , A[200003] , pot[200003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> K; for(int i = 1 ; i <= N ; ++i) pot[i] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; pot[A[i]]++;}
		int mnlen = 1e9 , mnx = 0 , pos = 0 , sum = 0;
		for(int i = 1 ; i <= N ; ++i){
			sum -= pot[i - 1]; while(pos <= N && sum - (N - sum) < K) sum += pot[++pos];
			if(pos <= N && mnlen > pos - i){mnlen = pos - i; mnx = i;}
		}
		vector < int > val;
		for(int i = 1 ; i <= N ; ++i){
			pot[i] = pot[i - 1] + (A[i] >= mnx && A[i] <= mnx + mnlen ? 1 : -1);
			if(pot[i] > (int)val.size()) val.push_back(i);
		}
		cout << mnx << ' ' << mnlen + mnx << endl; int pre = 0;
		for(int i = 0 ; i < K ; ++i){
			int cur = i == K - 1 ? N : val[i];
			cout << pre + 1 << ' ' << cur << endl; pre = cur;
		}
	}
	return 0;
}