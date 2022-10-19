#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qabs(int a){
	return (a < 0) ? -a : a;
}

int T;
int n, m; 
string ans[22];
void nxt(int& x, int& y){
	if(x == 0 && y < m - 1){
		y++;
	} else if(x < n - 1 && y == m - 1){
		x++;
	} else if(x == n - 1 && y > 0){
		y--;
	} else {
		x--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n){
			ans[i] = "";
			rep(j, m)
				ans[i] += '0';
		}
		ans[0][0] = '1';
		int x = 0, y = 2;
		while(x || y){
			int nxtx = x, nxty = y;
			nxt(nxtx, nxty);
			if(!nxtx && !nxty)
				break;
			nxt(nxtx, nxty);
			while((nxtx || nxty) && qabs(nxtx - x) <= 1 && qabs(nxty - y) <= 1)
				nxt(nxtx, nxty);
			if(qabs(nxtx - x) <= 1 && qabs(nxty - y) <= 1 && !nxtx && !nxty)
				break;
			ans[x][y] = '1';
			x = nxtx, y = nxty;
		}
		rep(i, n)
			cout << ans[i] << endl; 
	} 
	return 0;
}