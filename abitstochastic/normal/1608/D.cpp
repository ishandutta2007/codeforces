#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

int main(){
	int N; bool allw = 1 , allb = 1; int cnt0 = 0 , cnt1 = 0 , num = 1 , ans = 1; cin >> N;
	if(N == 1){
		string str; cin >> str;
		cout << (str == "??" ? 2 : str != "BB" && str != "WW") << endl; return 0;
	}
	for(int i = 1 ; i <= N ; ++i){
		string str; cin >> str; if(str[1] != '?') str[1] = 'W' + 'B' - str[1];
		allw &= str[0] != 'B' && str[1] != 'B'; allb &= str[0] != 'W' && str[1] != 'W';
		if(str == "??"){num = 2ll * num % P; cnt1 += 2; --cnt0;}
		else{
			if(str[0] == str[1] && str[0] != '?') continue;
			int cntr = str[0] != 'B' && str[1] != 'W' , cnt = !(str[0] != '?' && str[1] != '?' && str[0] != str[1]) , cntl = str[0] != 'W' && str[1] != 'B';
			if(cntr + cnt + cntl > 1){++cnt1; cnt0 -= cntr;} else cnt0 -= cntr - cntl;
			if(!cnt) num = 0;
		}
	}
	cnt0 = -cnt0;
	if(cnt0 >= 0 && cnt0 <= cnt1) for(int i = 1 ; i <= cnt0 ; ++i) ans = 1ll * ans * (cnt1 - i + 1) % P * poww(i , P - 2) % P; else ans = 0;
	cout << (ans - num + allw + allb + P) % P;
	return 0;
}