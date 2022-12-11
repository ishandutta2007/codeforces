
// Problem : C. Polo the Penguin and XOR operation
// Contest : Codeforces - Codeforces Round #177 (Div. 1)
// URL : https://codeforces.com/problemset/problem/288/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	iota(arr, arr+N+1, 0);
	int crnt = N;
	while(crnt > 0){
		int b = 31 - __builtin_clz(crnt);
		int rng = crnt - (1<<b) + 1;
		reverse(arr + crnt - 2*rng + 1, arr + crnt + 1);
		crnt -= 2*rng;
	}
	cout << 1LL*N*(N+1) << "\n";
	for(int i = 0; i<=N; i++){
		cout << arr[i] << " ";
	}
}