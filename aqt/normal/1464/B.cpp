
// Problem : B. Grime Zoo
// Contest : Codeforces - Codeforces Round #692 (Div. 1, based on Technocup 2021 Elimination Round 3)
// URL : https://codeforces.com/contest/1464/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s;
long long x, y;
long long pre[3][100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> x >> y;
	int N = s.size();
	long long ans = LLONG_MAX;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '0'){
			pre[0][i]++;
		}
		else if(s[i-1] == '1'){
			pre[1][i]++;
		}
		else{
			pre[2][i]++;
		}
		pre[0][i] += pre[0][i-1];
		pre[1][i] += pre[1][i-1];
		pre[2][i] += pre[2][i-1];
	}
	long long C = 0;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '0'){
			C += y * pre[1][i];
			C += x * (pre[1][N] - pre[1][i]);
		}
		else if(s[i-1] == '1'){
			C += x * pre[0][i];
			C += y * (pre[0][N] - pre[0][i]);
		}
	}
	C /= 2;
	long long T = 0;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '?'){
			T += x * pre[0][i];
			T += y * (pre[0][N] - pre[0][i]);
		}
	}
	ans = min(ans, T+C);
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '?'){
			T -= x * pre[0][i];
			T -= y * (pre[0][N] - pre[0][i]);
			T += y * pre[1][i];
			T += x * (pre[1][N] - pre[1][i]);
			ans = min(ans, T+C+x*pre[2][i]*(pre[2][N]-pre[2][i]));
		}
	}
	T = 0;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '?'){
			T += y * pre[1][i];
			T += x * (pre[1][N] - pre[1][i]);
		}
	}
	ans = min(ans, T + C);
	for(int i =1 ; i<=N; i++){
		if(s[i-1] == '?'){
			T -= y * pre[1][i];
			T -= x * (pre[1][N] - pre[1][i]);
			T += x * pre[0][i];
			T += y * (pre[0][N] - pre[0][i]);
			ans = min(ans, T+C+y*(pre[2][i])*(pre[2][N]-pre[2][i]));
		}
	}
	cout << ans;
}