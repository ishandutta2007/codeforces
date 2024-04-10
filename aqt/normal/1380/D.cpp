
// Problem : Berserk And Fireball
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1380/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[200005], brr[200005], idx[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	long long X, K, Y;
	cin >> X >> K >> Y;
	arr[N+1] = N+1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		idx[arr[i]] = i;
	}
	idx[N+1] = N+1;
	for(int i =1 ; i<=M; i++){
		cin >> brr[i];
	}
	brr[M+1] = N+1;
	long long ans = 0;
	for(int i = 1; i<=M+1; i++){
		if(idx[brr[i]] < idx[brr[i-1]]){
			ans = -1;
			break;
		}
		int rng = idx[brr[i]] - idx[brr[i-1]] - 1;
		if(rng == 0){
			continue;
		}
		int mx = 0;
		for(int j = idx[brr[i-1]]+1; j<idx[brr[i]]; j++){
			mx = max(mx, arr[j]);
		}
		if(mx > max(brr[i]%(N+1), brr[i-1])){
			if(rng < K){
				ans = -1;
				break;
			}
			ans += min(Y*(rng%K) + rng/K*X, (rng-K)*Y + X);
		}
		else{
			ans += min(Y*rng, Y*(rng%K) + rng/K*X);
		}
	}
	cout << ans << "\n";
}