#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = 1010, mod = int(1e9)  + 7; 

int n,m,k;
char s[N][N];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

int sx,sy;

int d[N][N];
char ch[4] = {'D','L','R','U'};

queue <pii> q;

int main () {
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i++){
		scanf("\n%s",s[i] + 1);
		for(int j = 1; j <= m; j++){
			if(s[i][j] == 'X'){
				sx = i;
				sy = j;
			}
		}
	}
	int res = 0;
	for(int i = 0; i < 4; i++){
		if(s[sx + dx[i]][sy + dy[i]] == '.') res++;
	}
	if(!res || k % 2 == 1){
		puts("IMPOSSIBLE");
		return 0;
	}
	memset(d, -1, sizeof(d));
	d[sx][sy] = 0;
	q.push(mp(sx,sy));
	while(!q.empty()){
		int x = q.front().f;
		int y = q.front().s;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(s[xx][yy] == '.' && d[xx][yy] == -1){
				d[xx][yy] = d[x][y] + 1;
				q.push(mp(xx,yy));
			}
		}
	}
	for(int i = k - 1; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			int x = dx[j] + sx;
			int y = dy[j] + sy;
			if(d[x][y] != -1 && d[x][y] <= i && (i - d[x][y]) % 2 == 0){
				sx = x;
				sy = y;
				putchar(ch[j]);
				break;
			}
		}	
	}
return 0;
}