
// Problem : F. The Struggling Contestant
// Contest : Codeforces - Codeforces Global Round 12
// URL : https://codeforces.com/contest/1450/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[1000005];
int fre[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int cnt = 0, val = 0;
		fill(fre+1, fre+1+N, 0);
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			if(val == arr[i]){
				cnt++;
			}
			else if(cnt == 0){
				cnt = 1;
				val = arr[i];
			}
			else{
				cnt--;
			}
		}
		if(2*count(arr+1, arr+1+N, val) > (N+1)){
			cout << -1 << "\n";
			continue;
		}
		fre[arr[1]]++;
		fre[arr[N]]++;
		int C = 1;
		for(int i = 2; i<=N; i++){
			if(arr[i] == arr[i-1]){
				fre[arr[i]] += 2;
				C++;
			}
		}
		int mx = *max_element(fre+1, fre+1+N);
		while(2*mx > 2*C + 2){
			C++;
		}
		cout << C-1 << "\n";
	}
}