#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// Problem : F. String Compression
// Contest : Codeforces - Educational Codeforces Round 25
// URL : https://codeforces.com/problemset/problem/825/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int hsh[8005];
int pows[8005];
const int MOD = 1e9+7;
const int sd = 143;
short dp[8005];
short per[8005][8005];
short f[8005];

int add(long long a, long long b){
	return (a+b)%MOD;
}

int mult(long long a, long long b){
	return (a*b)%MOD;
}

int sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
}

int  subhsh(int l, int r){
	return sub(hsh[r], mult(hsh[l-1], pows[r-l+1]));
}

int mylog(int n){
	if(n <= 0){
		return 0;
	}
	else if(n < 10){
		return 1;
	}
	else if(n < 100){
		return 2;
	}
	else if(n < 1000){
		return 3;
	}
	return 4;
}

inline void minn(short &a, short b){
	if(a > b){
		a = b;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	N = s.size();
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		pows[i] = mult(pows[i-1], sd);
		hsh[i] = add(mult(hsh[i-1], sd), s[i-1]);
		f[i] = mylog(i);
	}
	for(int i = 0; i<=N; i++){
		for(int j = 0; j<i; j++){
			per[i][j] = i - j;
		}
	}
	for(short l = 1; l<=N; l++){
		for(short r = 0; r<l; r++){
			short lst = r;
			int prev = -1;
			for(short i = r+l; i<=N; i+=l){
				const int h = subhsh(i-l+1, i);
				if(h != prev){
					lst = i - l;
					prev = h;
				}
				minn(per[i][lst], l);
			}
		}
	}
	for(short l = N; l; l--){
		for(short i = 0; i+l <= N; i++){
			short k = per[i+l][i];
			minn(per[i+l-k][i], k);
			minn(per[i+l][i+k], k);
		}
	}
	for(int i = 1; i<=N; i++){
		dp[i] = N+10;
		for(int j = 0; j<i; j++){
			minn(dp[i], (short) (dp[j] + per[i][j] + f[(i - j)/per[i][j]]));
		}
	}
	cout << dp[N];
}