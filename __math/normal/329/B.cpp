#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

char board[1000][1000 + 10];

int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};

int cost[1000][1000];

int main(){
	int h,w; cin>>h>>w;
	FOR(i,h) cin>>board[i];

	int sh,sw,eh,ew;
	FOR(i,h) FOR(j,w){
		if(board[i][j] == 'S'){
			sh = i,sw = j;
		} else if(board[i][j] == 'E'){
			eh = i,ew = j;
		}
	}

	memset(cost,0x3F,sizeof(cost));
	cost[eh][ew] = 0;
	queue<Pii> q;
	q.push(Pii(eh,ew));
	while(!q.empty()){
		int ch = q.front().first,cw = q.front().second;
		q.pop();

		FOR(i,4){
			int nh = dy[i] + ch,nw = dx[i] + cw;
			if(0 <= nh && nh < h && 0 <= nw && nw < w){
				if(board[nh][nw] == 'T') continue;
				if(cost[nh][nw] == 0x3F3F3F3F){
					cost[nh][nw] = cost[ch][cw] + 1;
					q.push(Pii(nh,nw));
				}
			}
		}
	}

	int ans = 0;
	int border = cost[sh][sw];
	FOR(i,h) FOR(j,w){
		if(board[i][j] >= '1' && board[i][j] <= '9'){
			if(border >= cost[i][j]){
				ans += board[i][j] - '0';
			}
		}
	}

	cout << ans << endl;

}