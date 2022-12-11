
// Problem : C. Little Alawn's Puzzle
// Contest : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1534/problem/C
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int dsu[400005];
int arr[400005];
int brr[400005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i =1 ; i <=N; i++){
			cin >> arr[i];
			dsu[i] = i;
		}
		bool good = 1;
		int C = N;
		for(int i = 1; i <= N; i++){
			cin >> brr[i];
			if(arr[i] == brr[i]){
				good = 0;
			}
			if(getrt(arr[i]) != getrt(brr[i])){
				dsu[getrt(arr[i])] = getrt(brr[i]);
				C--;
			}
		}
		if(!good){
			cout << 0 << "\n";
			continue;
		}
		long long ans = 1;
		while(C--){
			ans *= 2;
			ans %= 1000000007;
		}
		cout << ans << "\n";
	}
}