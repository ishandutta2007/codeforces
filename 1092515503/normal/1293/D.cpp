#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define x first
#define y second
pii p[1000],s;
int ax,bx,ay,by,sz,T,cnt,dis[1000],Dis[1000][1000],res;
int DIS(pii u,pii v){
	return abs(u.x-v.x)+abs(u.y-v.y);
}
signed main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&p[0].x,&p[0].y,&ax,&ay,&bx,&by);
	scanf("%I64d%I64d%I64d",&s.x,&s.y,&T);
	while(ax*p[cnt].x+bx<=s.x+T&&ay*p[cnt].y+by<=s.y+T)p[cnt+1]=make_pair(ax*p[cnt].x+bx,ay*p[cnt].y+by),cnt++;
	for(int i=0;i<=cnt;i++)dis[i]=DIS(p[i],s);
//	for(int i=0;i<=cnt;i++)printf("%lld %lld\n",p[i].x,p[i].y);
	for(int i=0;i<=cnt;i++)for(int j=0;j<=cnt;j++)Dis[i][j]=DIS(p[i],p[j]);
	for(int i=0;i<=cnt;i++)for(int j=i;j<=cnt;j++)for(int k=i;k<=j;k++)if(dis[k]+min(Dis[k][i],Dis[k][j])+Dis[i][j]<=T)res=max(res,j-i+1);
	printf("%I64d\n",res);
	return 0;
}