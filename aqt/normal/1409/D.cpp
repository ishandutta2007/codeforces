
// Problem : D. Decrease the Sum of Digits
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long pows[20];

long long rec(long long lim, long long s, long long crnt, int n, bool border){
	if(n == -1){
		if(s >= 0){
			return crnt - lim;
		}
		else{
			return LLONG_MAX/2;
		}
	}
	if(border){
		int d = lim/pows[n]%10;
		long long ret = LLONG_MAX/2;
		if(s > d && d != 9){
			ret = min(ret, rec(lim, s-d-1, crnt + pows[n] * (d+1), n-1, 0));
		}
		ret = min(ret, rec(lim, s-d, crnt + pows[n] * d, n-1, 1));
		return ret;
	}
	else{
		/*
		if(s >= 9){
			return rec(lim, s-9, crnt + pows[n] * 9, n-1, 0);
		}
		else{
			return rec(lim, 0, crnt + pows[n] * s, n-1, 0);
		}
		*/
		return rec(lim, s, crnt, n-1, 0);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	pows[0] = 1;
	for(int i = 1; i<=18; i++){
		pows[i] = pows[i-1] * 10;
	}
	while(T--){
		long long N, S;
		cin >> N >> S;
		if(N == 1000000000000000000LL){
			cout << 0 << "\n";
			continue;
		}
		cout << rec(N, S, 0, 18, 1) << "\n";
	}
}