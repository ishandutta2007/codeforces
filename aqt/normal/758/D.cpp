
// Problem : D. Ability To Convert
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

unsigned long long mylog(unsigned long long n){
	if(n == 0){
		return -1;
	}
	unsigned long long cnt = 0;
	unsigned long long crnt = 1;
	while(1){
		if(crnt*10 > n){
			break;
		}
		cnt++;
		crnt *= 10;
	}
	return cnt;
}

unsigned long long mypow(unsigned long long e){
	unsigned long long ret = 1;
	while(e--){
		ret *= 10;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned long long N, K;
	cin >> N;
	string s;
	cin >> s;
	unsigned long long ans = 0;
	unsigned long long b = 1;
	while(s.size()){
		//bool iszero = (K.back() == 0);
		unsigned long long v = 0;
		string T = s;
		unsigned long long b10 = 0;
		while(T.size()){
			//cout << v+(T.back()-'0')*mypow(mylog(v)+1) << endl;
			if(v + (T.back()-'0')*mypow(b10) >= N){
				break;
			}
			v += (T.back()-'0')*mypow(b10);
			T = T.substr(0, T.size()-1);
			b10++;
		}
		ans += v*b;
		b *= N;
		unsigned long long e = mylog(v)+1;
		if(!v){
			e = 1;
		}
		while(e--){
			s = s.substr(0, s.size()-1);
		}
	}
	cout << ans << "\n";
}