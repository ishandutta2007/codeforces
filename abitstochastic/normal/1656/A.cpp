#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int N; cin >> N; vector < int > pot(N);
		for(int i = 0 ; i < N ; ++i) cin >> pot[i];
		int mx = 0 , mn = 0;
		for(int i = 1 ; i < N ; ++i){
			if(pot[i] > pot[mx]) mx = i;
			if(pot[i] < pot[mn]) mn = i;
		}
		cout << mn + 1 << ' ' << mx + 1 << endl;
	}
	return 0;
}