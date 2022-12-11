
// Problem : A. A Twisty Movement
// Contest : Codeforces - Codeforces Round #462 (Div. 1)
// URL : https://codeforces.com/contest/933/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2005];
int pre[2][2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i] == 1){
			pre[0][i]++;
		}
		else{
			pre[1][i]++;
		}
		pre[0][i] += pre[0][i-1];
		pre[1][i] += pre[1][i-1];
	}
	int ans = 0;
	for(int l = 1; l<=N; l++){
		int mx = -pre[0][l-1] + pre[1][l-1];
		for(int r = l; r<=N; r++){
			mx = max(mx, -pre[0][r] + pre[1][r]);
			ans = max(ans, pre[0][l-1] + pre[1][N] - pre[1][r] + pre[0][r] - pre[1][l-1] + mx);
		}
	}
	cout << ans;
}