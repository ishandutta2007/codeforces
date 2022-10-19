#include<bits/stdc++.h>
#define ll long long
#define N 25
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,tot,t,a[N],tb,sx,sy,px[N],py[N];
int dis[N][N][(1<<8)+10],dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
char s[N][N];
void init(){
	rep(i,1,n) rep(j,1,m){
		if('0' <= s[i][j] && s[i][j] <= '9') px[s[i][j]-'0'] = i,py[s[i][j]-'0'] = j,t++;
	}
	rep(i,1,t) scanf("%d",&a[i]);
	tb = t;
	rep(i,1,n) rep(j,1,m){
		if(s[i][j] == 'B') ++tb,px[tb] = i,py[tb] = j;
		if(s[i][j] == 'S') sx = i,sy = j;
	}
}
struct node{
	int x,y,msk;
	node(){}
	node(int a,int b,int c){x = a;y = b;msk = c;}
};
queue<node> q;
bool check(int x,int y){
	return (1 <= x && x <= n) && (1 <= y && y <= m) && (s[x][y] == '.' || s[x][y] == 'S');
}
void bfs(){
	memset(dis,inf,sizeof dis);
	dis[sx][sy][0] = 0;
	q.push(node(sx,sy,0));
	while(!q.empty()){
		int x = q.front().x,y = q.front().y,msk = q.front().msk,d = dis[x][y][msk];
		// printf("%d %d %d %d\n",x,y,msk,d);
		q.pop();
		rep(i,0,3){
			int tx = x+dx[i],ty = y+dy[i],tmsk = msk;
			if(!check(tx,ty)) continue; 
			if(dx[i] == 1)
				rep(i,1,tb) if(px[i] == tx && py[i] < ty) tmsk ^= (1<<(i-1));
			if(dx[i] == -1)
				rep(i,1,tb) if(px[i] == x && py[i] < y) tmsk ^= (1<<(i-1));
			// if(dy[i] != 0){
			// 	rep(i,1,tb) if(py[i] == ty && px[i] < tx) tmsk ^= (1<<(i-1));
			// }
			if(dis[tx][ty][tmsk] > d+1){
				dis[tx][ty][tmsk] = d+1;
				q.push(node(tx,ty,tmsk));
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i]+1);
	init();
	// printf("%d %d\n",t,tb);
	// rep(i,1,tb) printf("pos: %d %d\n",px[i],py[i]);
	bfs();
	int ans = 0;
	rep(msk,0,(1<<t)-1){
		// rep(i,t+1,tb) msk |= (1<<(i-1));
		int res = 0;
		rep(i,1,t) if(((1<<(i-1))&msk)) res += a[i];
		ans = max(ans,res-dis[sx][sy][msk]);
	} 
	printf("%d\n",ans);
	return 0;
}
/*
4 4
....
.S1.
..#.
....
10

2 2 1 0
3 2 1 1
1 2 1 1
2 1 1 1
4 2 1 2
3 1 1 2
1 3 1 2
1 1 1 2
4 3 1 3
4 1 1 3
1 4 1 3

2 4 0 4
1 4 0 5
1 3 0 6
1 2 0 7
2 2 0 8
*/