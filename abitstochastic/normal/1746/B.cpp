#include<bits/stdc++.h>
using namespace std;

int arr[200003] , N , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		int pos1 = 1 , pos2 = N;
		for(int i = 1 ; i <= N ; ++i){
			while(pos1 < N + 1 && arr[pos1] == 0) ++pos1;
			while(pos2 && arr[pos2] == 1) --pos2;
			if(pos2 <= pos1){cout << i - 1 << endl; break;}
			++pos1; --pos2;
		}
	}
	return 0;
}