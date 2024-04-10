
// Problem : F. Network Coverage
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[1000005];
int brr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		long long s = 0;
		for(int i = 0; i<N; i++){
			cin >> arr[i];
			s += arr[i];
		}
		for(int i = 0; i<N; i++){
			cin >> brr[i];
			s -= brr[i];
		}
		bool good = (s <= 0);
		s = 0;
		for(int i = 0; i<2*N; i++){
			s += arr[i%N] - brr[(i+N-1)%N];
			s = max(s, 0LL);
			//cout << i << " " << s << "\n";
			if(s - brr[i%N] > 0){
				//cout << i << "\n";
				good = 0;
			}
		}
		if(good){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}