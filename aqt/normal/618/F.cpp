
// Problem : F. Double Knapsack
// Contest : Codeforces - Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
// URL : https://codeforces.com/contest/618/problem/F
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[1000005];
long long brr[1000005];
int nxt[1000005];
int lst[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] += arr[i-1];
		lst[i] = -1;
	}
	lst[0] = -1;
	for(int i = 1; i<=N; i++){
		cin >> brr[i];
		brr[i] += brr[i-1];
	}
	if(arr[N] < brr[N]){
		int idx = 0;
		for(int i = 0; i<=N; i++){
			while(arr[i] - brr[idx] >= N){
				idx++;
			}
			nxt[i] = idx;
			int d = arr[i]-brr[idx];
			if(lst[d]+1){
				cout << i - lst[d] << "\n";
				for(int k = lst[d]+1; k<=i; k++){
					cout << k << " ";
				}
				cout << "\n";
				cout << nxt[i] - nxt[lst[d]] << "\n";
				for(int k = nxt[lst[d]]+1; k<=nxt[i]; k++){
					cout << k << " ";
				}
				return 0;
			}
			else{
				lst[d] = i;
			}
		}
	}
	else{
		int idx = 0;
		for(int i = 0; i<=N; i++){
			while(brr[i] - arr[idx] >= N){
				idx++;
			}
			nxt[i] = idx;
			int d = brr[i] - arr[idx];
			if(lst[d]+1){
				cout << nxt[i] - nxt[lst[d]] << "\n";
				for(int k = nxt[lst[d]]+1; k<=nxt[i]; k++){
					cout << k << " ";
				}
				cout << "\n";				
				cout << i - lst[d] << "\n";
				for(int k = lst[d]+1; k<=i; k++){
					cout << k << " ";
				}
				return 0;				
			}
			else{
				lst[d] = i;
			}
		}	
	}
}