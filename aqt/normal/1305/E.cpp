
// Problem : E. Kuroni and the Score Distribution
// Contest : Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/contest/1305/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[5005];
int pre[5005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		arr[i] = i;
	}
	int tot = 0;
	for(int i = 1; i<=N; i++){
		tot += (i-1)/2;
	}
	if(M > tot){
		cout << -1 << "\n";
		return 0;
	}
	for(int i = N; i; i--){
		if(tot-(i-1)/2 > M){
			arr[i] = 1000000000-(N-i)*50000;
			tot -= (i-1)/2;
		}
		else{
			arr[i] += 2*(tot-M);
			break;
		}
	}
	//partial_sum(pre, pre+1+N, pre);
	for(int i = 1; i<=N; i++){
		cout << arr[i] + pre[i] << " ";
	}
}