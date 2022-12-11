
// Problem : C. Prefix Product Sequence
// Contest : Codeforces - Codeforces Round #278 (Div. 1)
// URL : https://codeforces.com/contest/487/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret *= ret;
	ret %= N;
	if(e&1){
		ret *= b;
		ret %= N;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	bool good = 1;
	if(N == 4){
		cout << "YES\n" << "1\n" << "3\n" << "2\n" << "4\n" << endl;
		return 0;
	}
	for(int k = 2; k < N; k++){
		if(N%k == 0){
			good = 0;
		}
	}
	if(good){
		cout << "YES\n";
		cout << 1 << "\n";
		for(int i = 2; i < N; i++){
			cout << i * qikpow(i-1, N - 2) % N << "\n";
		}
		if(1 != N){
			cout << N << "\n";
		}
	}	
	else{
		cout << "NO\n";
	}
}