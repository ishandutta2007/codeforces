#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef pair<int,int> pii;
const int mx = 1003, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
const int inf = 1e8;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	char map[mx][mx];
	rep(i,0,mx) rep(j,0,mx) map[i][j] = '#';
	rep(i,1,n+1) rep(j,1,m+1) scanf(" %c ",&map[i][j]);
	int d[3][mx][mx];
	memset(d,-1,sizeof(d));
	rep(i,0,mx) rep(j,0,mx)
		if(map[i][j] == '#')
			rep(t,0,3) d[t][i][j] = inf;
	rep(t,0,3){
		queue<pii> ko;
		rep(i,1,n+1) rep(j,1,m+1)
			if(map[i][j] == '1' + t){
				ko.push(pii(i,j));
				d[t][i][j] = 0;
			}
		while(!ko.empty()){
			int x = ko.front().first, y = ko.front().second;
			ko.pop();
			rep(dir,0,4)
				if(d[t][x+dx[dir]][y+dy[dir]] == -1){
					d[t][x+dx[dir]][y+dy[dir]] = 1 + d[t][x][y];
					ko.push(pii(x+dx[dir], y+dy[dir]));
				}
		}
	}
	int br[] = {inf,inf,inf}, str = inf;
	rep(i,1,n+1) rep(j,1,m+1){
		int alt = -2;
		rep(t,0,3) alt += d[t][i][j] == -1 ? inf : d[t][i][j];
		str = min(str, alt);
		rep(t,0,3)
			if(d[t][i][j] == 0){
				rep(k,0,3)
					if(k != t){
						int l = (3-t-k)%3;
						br[l] = min(br[l], (d[k][i][j] == -1 ? int(inf) : d[k][i][j])-1);
					}
			}
	}
	sort(br,br+3);
	int ans = min(br[0]+br[1], str);
	printf("%d\n",ans < 1e7 ? ans : -1);
}