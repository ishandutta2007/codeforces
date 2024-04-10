#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include<bits/stdc++.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, m;
string c[111];
int LR=2;
int UD=2;
string slr = "LR";
string sud = "UD";
int cnt = 0;
pii goLR(int x, int y, int ind){
	if(c[x][y] == 'F') exit(0);
	cnt++;
	assert(cnt <= 2 * n * m);
	if(LR == 2){
		cout << slr[1] << endl;
		fflush(stdout);
		int a, b;
		cin >> a >> b;

		if(a == -1 || b==-1) assert(false);
		if(x == a && b == y) LR = 1;
		else LR = 0;
		if(c[a][b] == 'F') exit(0);
		return mp(a, b);
	}
	else {
		cout << slr[ind^LR] << endl;
		fflush(stdout);
		int a, b;
		cin >> a >> b;

		if(a == -1 || b==-1) assert(false);

		if(c[a][b] == 'F') exit(0);
		return mp(a, b);
	}
}
pii goUD(int x, int y, int ind){
	if(c[x][y] == 'F') exit(0);
	cnt++;

	assert(cnt <= 2 * n * m);
	if(UD == 2){
		cout << sud[1] << endl;
		fflush(stdout);
		int a, b;
		cin >> a >> b;
		
		if(a == -1 || b==-1) assert(false);
		if(x == a && b == y) UD = 1;
		else UD = 0;
		if(c[a][b] == 'F') exit(0);
		return mp(a, b);
	}
	else {
		cout << sud[ind^UD] << endl;
		fflush(stdout);
		int a, b;
		cin >> a >> b;

		
		if(a == -1 || b==-1) assert(false);		
		
		if(c[a][b] == 'F') exit(0);
		return mp(a, b);
	}
}
int u[111][111];
pii p[111][111];
void solve(){
	cin >> n >> m;
	for(int i =1; i <= n; i++){
		cin >> c[i];
		c[i] = ' ' + c[i];

	}
	if(c[1][1] == 'F') exit(0);
	//for(int i = 1; i <= n; i++)
	//	cout << c[i] << endl;
	
	int x = 1;
	int y = 1;
	cnt= 0;
	if(n == 1 || c[2][1] == '*'){
		pii xd = goLR(x, y, 1);
		x = xd.f;
		y = xd.s;
		while(true){
			//cout << x << " "<< y << endl;
			if(x < n && c[x + 1][y] != '*'){		
				pii xd = goUD(x, y, 1);
				x = xd.f;
				y = xd.s;
				break;
			}
			else {
				if(y==m) break;
				pii xd = goLR(x, y, 1);
				x = xd.f;
				y = xd.s;
			}
		}
	}else {
		//cerr<<"adfad"<<endl;
		pii xd = goUD(x, y, 1);
		x = xd.f;
		y = xd.s;
		while(true){
			if(y < m && c[x][y + 1] != '*'){		
				pii xd = goLR(x, y, 1);
				x = xd.f;
				y = xd.s;
				break;
			}
			else {
				if(x==n || c[x + 1][y] == '*') break;
				pii xd = goUD(x, y, 1);
				x = xd.f;
				y = xd.s;
			}
		}
		if(LR == 2){
			while(true){
				if(y < m && c[x][y + 1] != '*'){		
					pii xd = goLR(x, y, 1);
					x = xd.f;
					y = xd.s;
					break;
				}
				else {
					if(x==1) break;
					pii xd = goUD(x, y, 0);
					x = xd.f;
					y = xd.s;
				}
			}
		}
	}
	assert(LR < 2 && UD < 2);
	int stx, sty;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(c[i][j] == 'F') stx = i, sty = j;
		}
	}
	queue<pii> q;
	u[stx][sty] = 1;
	//cout << stx << " "<< sty << endl;
	q.push(mp(stx, sty));
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	while(q.size() > 0){
		pii cc = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int X = dx[i] + cc.f;
			int Y = dy[i] + cc.s;
			if(X > 0 && X <= n && Y > 0 && Y <= m && c[X][Y] != '*' && !u[X][Y]){
				u[X][Y] = 1;
				p[X][Y] = cc;
				q.push(mp(X, Y));
			}
		}
	}

	assert(p[x][y].s > 0);
	assert(cnt <= 2 * n * m);
	while(true){
		if(p[x][y].f == 0||p[x][y].s == 0) assert(false);

		if(p[x][y].s>0 && p[x][y].s - 1== y) {
			if(p[x][y].f != x) assert(false);	
			pii xd = goLR(x, y, 1);
			x = xd.f;
			y = xd.s;
		}
		else if(p[x][y].s>0 && p[x][y].s + 1== y) {
			if(p[x][y].f != x) assert(false);
			pii xd = goLR(x, y, 0);
			x = xd.f;
			y = xd.s;
		}else if(p[x][y].s>0 && p[x][y].f + 1 == x){
			
			if(p[x][y].s != y) assert(false);
			pii xd = goUD(x, y, 0);
			x = xd.f;
			y = xd.s;
		}
		else if(p[x][y].s>0){
			if(p[x][y].s != y) assert(false);
			pii xd = goUD(x, y, 1);

			x = xd.f;
			y = xd.s;
		}
		else assert(false);
		assert(cnt <= 2 * n * m);
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}