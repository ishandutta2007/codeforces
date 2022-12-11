
// Problem : B. Trouble Sort
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		bool srt = 1;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			if(arr[i] < arr[i-1]){
				srt = 0;
			}
		}
		int typ = 0;
		for(int i =1; i<=N; i++){
			int c;
			cin >> c;
			typ |= (1<<c);
		}
		if(srt || typ == 3){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}