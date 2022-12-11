
// Problem : C. Mere Array
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[100005];
int srt[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i =1; i<=N; i++){
			cin >> arr[i];
			srt[i] = arr[i];
		}
		int M = *min_element(arr+1, arr+1+N);
		sort(srt+1, srt+1+N);
		bool pos = 1;
		for(int i = 1; i<=N; i++){
			if(arr[i] != srt[i] && arr[i]%M){
				pos = 0;
			}
		}
		cout << (pos ? "YES\n" : "NO\n");
	}
}