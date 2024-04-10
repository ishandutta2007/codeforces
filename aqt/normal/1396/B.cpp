
// Problem : B. Stoned Game
// Contest : Codeforces - Codeforces Round #666 (Div. 1)
// URL : https://codeforces.com/contest/1396/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i =1 ; i<=N; i++){
			cin >> arr[i];
		}
		int lst = 0, cnt =0;
		while(1){
			int mx = 0;
			for(int i = 1; i<=N; i++){
				if(i != lst && arr[mx] < arr[i]){
					mx = i;
				}
			}
			if(mx){
				cnt++;
				lst = mx;
				arr[mx]--;
			}
			else{
				break;
			}
		}
		if(cnt%2 == 0){
			cout << "HL\n";
		}
		else{
			cout << "T\n";
		}
	}
}