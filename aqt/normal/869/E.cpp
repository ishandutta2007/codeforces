
// Problem : E. The Untended Antiquity
// Contest : Codeforces Round #439 (Div. 2)
// URL : https://codeforces.com/contest/869/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
long long bit[2505][2505];
map<pair<int, int>, long long> mp;

void upd(int x, int y, long long v){
	for(int i = x; i<=N; i+=i&-i){
		for(int j = y; j<=M; j+=j&-j){
			bit[i][j] ^= v;
		}
	}
}

long long query(int x, int y){
	long long ret = 0;
	for(int i = x; i; i-=i&-i){
		for(int j = y; j; j-=j&-j){
			ret ^= bit[i][j];
		}
	}
	return ret;
}

void totupd(int x1, int y1, int x2, int y2, long long v){
	x2++, y2++;
	upd(x1, y1, v);
	upd(x1, y2, v);
	upd(x2, y1, v);
	upd(x2, y2, v);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	while(Q--){
		int c, x1, y1, x2, y2;
		cin >> c >> x1 >> y1 >> x2 >> y2;
		if(c == 1){
			long long v = 1LL*rand() * RAND_MAX * RAND_MAX * RAND_MAX + rand() * RAND_MAX * RAND_MAX + rand() * RAND_MAX + rand();
			totupd(x1, y1, x2, y2, v);
			mp[{x1, y1}] = v;
		}
		else if(c == 2){
			long long v = mp[{x1, y1}];
			totupd(x1, y1, x2, y2, v);
			mp.erase({x1, y1});
		}
		else{
			if(query(x1, y1) == query(x2, y2)){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
	}
}