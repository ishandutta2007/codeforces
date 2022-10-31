#include<bits/stdc++.h>
#define N 1010
using namespace std;
bool can[N][N][4];
int dis[N][N][4];
char s[N][N];
int mx[4]={0,-1,0,1},my[4]={-1,0,1,0};
const int inf = 0x3f3f3f3f;
struct pos{
	int x;
	int y;
	int d;
	pos(){}
	pos(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
	pos turn()const{pos res=*this; res.d=(res.d+3)&3; return res;}
};
inline int get_dis(pos a){
	return dis[a.x][a.y][a.d];
}
inline void upd_dis(pos a,int k){
	dis[a.x][a.y][a.d]=k;
}
inline pair<bool,pos> to(pos a,int n,int m,int d){
	pos b=a;
	b.x+=mx[d];
	b.y+=my[d];
	if(b.x<0||b.x>=n||b.y<0||b.y>=m) return make_pair(false,pos());
	if(!can[a.x][a.y][(a.d+d)&3]) return make_pair(false,pos());
	if(!can[b.x][b.y][(b.d+d+2)&3]) return make_pair(false,pos());
	return make_pair(true,b);
}
//0:L, 1:U, 2:R, 3:D
int main(){
	int n,m,x1,y1,x2,y2,ans=inf;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='+'||s[i][j]=='-'||s[i][j]=='<'||isupper(s[i][j])&&s[i][j]!='L') can[i][j][0]=true;
			if(s[i][j]=='+'||s[i][j]=='|'||s[i][j]=='^'||isupper(s[i][j])&&s[i][j]!='U') can[i][j][1]=true;
			if(s[i][j]=='+'||s[i][j]=='-'||s[i][j]=='>'||isupper(s[i][j])&&s[i][j]!='R') can[i][j][2]=true;
			if(s[i][j]=='+'||s[i][j]=='|'||s[i][j]=='v'||isupper(s[i][j])&&s[i][j]!='D') can[i][j][3]=true;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	--x1,--y1,--x2,--y2;
	queue<pos> q;
	q.push(pos(x1,y1,0));
	dis[x1][y1][0]=0;
	while(!q.empty()){
		pos u=q.front();
		q.pop();
		if(get_dis(u)+1<get_dis(u.turn())){
			upd_dis(u.turn(),get_dis(u)+1);
			q.push(u.turn());
		}
		for(int i=0;i<4;i++){
			auto tmp=to(u,n,m,i);
			if(tmp.first){
				pos v=tmp.second;
				if(get_dis(u)+1<get_dis(v)){
					upd_dis(v,get_dis(u)+1);
					q.push(v);
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		ans=min(ans,dis[x2][y2][i]);
	}
	if(ans<inf) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}