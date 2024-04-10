
// Problem : C. Permutation Partitions
// Contest : Codeforces Global Round 7
// URL : https://codeforces.com/contest/1326/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];
long long MOD = 998244353;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int lst = 0;
	long long tot = 0, cnt = 1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i] >= N-K+1){
			if(lst){
				cnt *= i-lst;
				cnt %= MOD;
			}
			lst = i;
			tot += arr[i];
		}
	}
	cout << tot << " " << cnt << "\n";
}