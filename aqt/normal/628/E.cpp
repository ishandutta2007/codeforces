
// Problem : E. Zbazi in Zeydabad
// Contest : Educational Codeforces Round 8
// URL : https://codeforces.com/contest/628/problem/E
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

short N, M;
bool mp[3005][3005];
short lft[3005][3005];
short rht[3005][3005];
short dia[3005][3005];
short bit[3005];
vector<short> v[3005];

void upd(short n, short k){
	while(n <= N){
		bit[n] += k;
		n += n&-n;
	}
}

short query(short n){
	short ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			char c;
			cin >> c;
			mp[i][j] = (c == 'z');
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			if(mp[i][j]){
				lft[i][j] = lft[i][j-1] + 1;
			}
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = M; j; j--){
			if(mp[i][j]){
				rht[i][j] = rht[i][j+1] + 1;
			}
		}
	}
	for(int i = N; i; i--){
		for(int j = 1; j<=M; j++){
			if(mp[i][j]){
				dia[i][j] = dia[i+1][j-1] + 1;
			}
		}
	}
	long long tot = 0;
	for(short d = 2; d<=N+M; d++){
		for(short i = 1; i<=N; i++){
			short j = d-i;
			if(j < 1 || j > M){
				continue;
			}
			if(!mp[i][j]){
				continue;
			}
			short lim = max(i-rht[i][j], 0);
			upd(i, 1);
			tot += query(i) - query(lim);
			short nxt = min(lft[i][j], dia[i][j]);
			if(i+nxt-1 <= N && j-nxt+1 > 0){
				v[i+nxt-1].emplace_back(i);
			}
			while(v[i].size()){
				short k = v[i].back();
				v[i].pop_back();
				upd(k, -1);
			}
		}
	}
	cout << tot << "\n";
}