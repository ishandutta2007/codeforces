
// Problem : B. Ants
// Contest : Codeforces - Codeforces Round #188 (Div. 1)
// URL : https://codeforces.com/contest/317/problem/B
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int offset = 250;
int mp[505][505];
bool tkn[505][505];
queue<pair<int, int>> qu;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	mp[offset][offset] = N;
	if(N >= 4){
		qu.push({0, 0});
	}
	int mx = 0;
	while(qu.size()){
		auto p = qu.front();
		//mx = max(mx, p.first);
		//mx = max(mx, p.second);
		qu.pop();
		tkn[p.first+offset][p.second+offset] = 0;
		int n = mp[p.first+offset][p.second+offset];
		n /= 4;
		mp[p.first+offset][p.second+offset] %= 4;
		//iterator ptr;
		if((mp[p.first+1+offset][p.second+offset] += n) >= 4 && !tkn[p.first+offset+1][p.second+offset]){
			tkn[p.first+1+offset][p.second+offset] = 1;
			qu.push({p.first+1, p.second});
		}
		if((mp[p.first-1+offset][p.second+offset] += n) >= 4 && !tkn[p.first+offset-1][p.second+offset]){
			tkn[p.first-1+offset][p.second+offset] = 1;
			qu.push({p.first-1, p.second});
		}		
		if((mp[p.first+offset][p.second+1+offset] += n) >= 4 && !tkn[p.first+offset][1+p.second+offset]){
			tkn[p.first+offset][1+p.second+offset] = 1;
			qu.push({p.first, 1+p.second});
		}
		if((mp[p.first+offset][p.second-1+offset] += n) >= 4 && !tkn[p.first+offset][-1+p.second+offset]){
			tkn[p.first+offset][-1+p.second+offset] = 1;
			qu.push({p.first, -1+p.second});
		}
	}
	//cout << mx << "\n";
	while(Q--){
		int x, y;
		cin >> x >> y;
		if(abs(x) <= 250 && abs(y) <= 250){
			cout << mp[x+offset][y+offset] << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}