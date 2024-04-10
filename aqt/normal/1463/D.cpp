
// Problem : D. Pairs
// Contest : Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1463/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[200005];
int brr[200005];
bool tkn[400005];

bool chk(int x){
	//cout << "chk: " << x << "\n";
	bool good = 1;
	for(int n = 1; n<=x; n++){
		//cout << arr[n] << " " <<  brr[N-x+n] << "\n";
		if(arr[n] > brr[N-x+n]){
			good = 0;
		}
	}
	for(int n = N; n>x; n--){
		//cout << arr[n] << " " << brr[n-x] << "\n";
		if(arr[n] < brr[n-x]){
			good = 0;
		}
	}
	return good;	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int x = 0;
		fill(tkn, tkn+1+2*N, 0);
		for(int i =1 ; i<=N; i++){
			cin >> arr[i];
			x += arr[i] <= N;
			tkn[arr[i]] = 1;
		}
		int idx = 0;
		for(int i = 1; i<=2*N; i++){
			if(!tkn[i]){
				brr[++idx] = i;
			}
		}
		int lb = x, ub = x;
		int l = 0, r = x;
		while(l <= r){
			int mid = l+r>>1;
			if(chk(mid)){
				r = mid - 1;
				lb = mid;
			}
			else{
				l = mid + 1;
			}
		}
		l = x, r = N;
		while(l <= r){
			int mid = l+r>>1;
			if(chk(mid)){
				l = mid + 1;
				ub = mid;
			}
			else{
				r = mid - 1;
			}
		}
		cout << ub - lb + 1 << "\n";
	}
}