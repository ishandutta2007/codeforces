#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , P = 1e9 + 7; int fib[_] , N , K , A[_] , ans;

int main(){
	cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	fib[0] = 1; fib[1] = 1; for(int i = 2 ; i <= K + 1 ; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
	for(int i = 1 ; i <= K ; ++i) fib[i] = (fib[i] + fib[i - 1]) % P;
	sort(A + 1 , A + N + 1); set < int > val; --K;
	for(int i = 1 ; i <= N ; ++i){
		int cur = A[i];
		do if(cur % 4 == 0) cur /= 4; else if(cur % 2) cur /= 2; else break; while(cur && val.find(cur) == val.end());
		if(val.find(cur) == val.end()){
			val.insert(A[i]); int log2 = -1; while(A[i]){++log2; A[i] >>= 1;}
			ans = (ans + (K < log2 ? 0 : fib[K - log2])) % P;
		}
	}
	cout << ans << endl;
	return 0;
}