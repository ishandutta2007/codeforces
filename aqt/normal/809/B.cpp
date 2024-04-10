
// Problem : B. Glad to see you!
// Contest : Codeforces - Codeforces Round #415 (Div. 1)
// URL : https://codeforces.com/contest/809/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;

bool query(int a, int b){
	//assert(b >= 1 && b <=N && a >= 1 && a <= N);
	cout << "1 " << a << " " << b << endl;
	string s;
	cin >> s;
	return s == "TAK";
}

int solve(int l, int r){
	while(l < r){
		int mid = (l+r)/2;
		if(query(mid, mid+1)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int n = solve(1, N);
	//cout << n << endl;
	if(n != 1){
		int k = solve(1, n-1);
		if(!query(k, n)){
			k = solve(n+1, N);
		}
		cout << 2 << " " << n << " " << k << endl;
		return 0;
	}
	int k = solve(n+1, N);
	cout << 2 << " " << n << " " << k << endl;
}