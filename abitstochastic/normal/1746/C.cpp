#include<bits/stdc++.h>
using namespace std;

int arr[200003] , N , T , ans[200003]; vector < int > pot[200003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int j = 1 ; j <= N ; ++j){cin >> arr[j]; pot[j].clear();}
		for(int j = 2 ; j <= N ; ++j)
			if(arr[j - 1] > arr[j]) pot[arr[j - 1] - arr[j]].push_back(j);
		int pos = N;
		for(int i = N ; i ; --i){
			while(pos && pot[pos].size() == 0) --pos;
			int t = 1; if(pos){t = pot[pos].back(); pot[pos].pop_back();}
			ans[i] = t;
		}
		for(int i = 1 ; i <= N ; ++i) cout << ans[i] << " \n"[i == N];
	}
	return 0;
}