
// Problem : E. Vus the Cossack and a Field
// Contest : Codeforces - Codeforces Round #571 (Div. 2)
// URL : https://codeforces.com/contest/1186/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int pre[1005][1005];

long long solve(int x, int y){
	int bx = x/(2*N), by = y/(2*M);
	long long ret = 1LL*bx*by*2*N*M;
	int mx = x%(2*N), my = y%(2*M);
	ret += (1LL * bx * my * N + 1LL * by * mx * M);
	bool inv = 0;
	int t = bx+1, s = by+1;
	for(int d = 29; d>=0; d--){
		if(t > (1<<d)){
			inv ^= 1;
			t -= (1<<d);
		}
		if(s > (1<<d)){
			inv ^= 1;
			s -= (1<<d);
		}
	}
	long long sum = 0;
	if(mx > N && my > M){
		sum = pre[N][M] + 1LL * N * (my % M) - pre[N][my%M];
		sum += 1LL * M * (mx % N) - pre[mx%N][M];
		sum += pre[mx%N][my%M];
	}
	else if(mx > N){
		sum = pre[N][my] + 1LL* (mx%N * my) - pre[mx%N][my];
	}
	else if(my > M){
		sum = pre[mx][M] + 1LL * (my%M * mx) - pre[mx][my%M];
	}
	else{
		sum = pre[mx][my];
	}
	//cout << inv << "\n";
	if(inv){
		sum = 1LL * my * mx - sum;
	}
	//cout << ret << " " << sum << "\n";
	return sum + ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i =1 ; i<=N; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=M; j++){
			pre[i][j] = s[j-1] == '1';
			pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}
	while(Q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << solve(x2, y2) - solve(x1-1, y2) - solve(x2, y1-1) + solve(x1-1, y1-1) << "\n";
	}
}