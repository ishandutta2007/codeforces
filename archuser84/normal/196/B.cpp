#include <bits/stdc++.h>
using namespace std;

const int N = 1510;
char s[N][N]; // the maze
int n, m;

int sx, sy; // position of S

int mx(int x){return (x%n+n)%n;}
int my(int y){return (y%m+m)%m;} // m stands for mod

bool vis[N][N];
int X[N][N], Y[N][N]; // true position of a visited cell

bool _dfs(int,int); // a subroutine for our dfs
bool dfs(int x, int y){ // returns the answer of the problem
	vis[mx(x)][my(y)] = true;
	X[mx(x)][my(y)] = x;
	Y[mx(x)][my(y)] = y;
	if(_dfs(x+1,y)) return true;
	if(_dfs(x-1,y)) return true;
	if(_dfs(x,y+1)) return true;
	if(_dfs(x,y-1)) return true;
	return false;
}
bool _dfs(int x, int y){
	if(vis[mx(x)][my(y)] && (X[mx(x)][my(y)] != x || Y[mx(x)][my(y)] != y))
		return true; // if we visited this cell in a different copy, the answer is yes
	if(!vis[mx(x)][my(y)] && s[mx(x)][my(y)] != '#')
		if(dfs(x,y))
			return true;
	return false;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> s[i][j];
			if(s[i][j] == 'S')
				sx = i, sy = j;
		}
	}

	cout << (dfs(sx,sy)? "Yes\n": "No\n");
}