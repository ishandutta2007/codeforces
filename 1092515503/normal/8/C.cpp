#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
pii a[50];
vector<int>tmp[50];
int n,m,half,res,ans[50],DIS[50][50],p[50];
inline int dis(int u,int v){
	return (a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y);
}
inline int calc(int *ip){
	register int ret=0;
	for(register int i=1;i<=m;i++)tmp[ip[i]].push_back(i);
	for(register int i=1;i<=half;i++)ret+=min(DIS[0][tmp[i][0]]*2+DIS[0][tmp[i][1]]*2,DIS[0][tmp[i][0]]+DIS[tmp[i][0]][tmp[i][1]]+DIS[tmp[i][1]][0]),tmp[i].clear();
	return ret;
}
double delta=0.99995;
inline void SA(){
	memcpy(p,ans,sizeof(ans));
	register double T=1000;
	while(T>1e-12){
		T*=delta;
		register int x=rand()%m+1,y=rand()%m+1;
		if(p[x]==p[y])continue;
		swap(p[x],p[y]);
		register int now=calc(p);
		register int DELTA=now-res;
		if(DELTA<0)res=now,memcpy(ans,p,sizeof(p));
		else if(exp(-DELTA/T)*RAND_MAX<rand())swap(p[x],p[y]);
	}
}
inline void CM(){
	memcpy(p,ans,sizeof(ans));
	for(int i=1;i<=50000;i++){
		register int x=rand()%m+1,y=rand()%m+1;
		if(p[x]==p[y])continue;
		swap(p[x],p[y]);
		register int now=calc(p);
		register int DELTA=now-res;
		if(DELTA<0)res=now,memcpy(ans,p,sizeof(p));
		else swap(p[x],p[y]);
	}
}
inline void CALC(){
	memcpy(p,ans,sizeof(ans));
	for(int i=0;i<10000;i++){
		random_shuffle(p+1,p+m+1);
		if(calc(p)<res)memcpy(ans,p,sizeof(p));
	}
	CM();
	while ((double)clock()/CLOCKS_PER_SEC<3.8) SA();
}
inline void read(int &x){
	x=0;
	char c=getchar();
	int flag=1;
	while(c>'9'||c<'0')flag=(c=='-'?-1:1),c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=flag;
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
int main(){
	read(a[0].x),read(a[0].y),srand(time(0)),srand(rand());
	read(n);
	for(register int i=1;i<=n;i++)read(a[i].x),read(a[i].y),a[i].x-=a[0].x,a[i].y-=a[0].y;
	a[0].x=a[0].y=0;
	m=n;
	if(m&1)m++;
	half=m/2;
	for(register int i=1;i<=m;i++)ans[i]=(i+1)/2;
//	for(int i=0;i<=m;i++)printf("(%d,%d)\n",a[i].first,a[i].second);
	for(register int i=0;i<=m;i++)for(register int j=0;j<=m;j++)DIS[i][j]=dis(i,j);
//	for(int i=0;i<=m;i++){for(int j=0;j<=m;j++)printf("%d ",DIS[i][j]);puts("");}
	random_shuffle(ans+1,ans+m+1);
	res=calc(ans);
	CALC();
//	printf("%d\n",calc(ans));
//	for(int i=1;i<=m;i++)printf("%d ",ans[i]);puts("");
	printf("%d\n",res);
	printf("%d ",0);
	for(register int i=1;i<=m;i++)tmp[ans[i]].push_back(i);
	for(register int i=1;i<=half;i++){
		if(tmp[i][0]<=n&&tmp[i][1]<=n){
			if(DIS[0][tmp[i][0]]*2+DIS[0][tmp[i][1]]*2<DIS[0][tmp[i][0]]+DIS[tmp[i][0]][tmp[i][1]]+DIS[tmp[i][1]][0])printf("%d 0 %d ",tmp[i][0],tmp[i][1]);
			else printf("%d %d ",tmp[i][0],tmp[i][1]);
		}else{
			if(tmp[i][0]<=n)printf("%d ",tmp[i][0]);
			if(tmp[i][1]<=n)printf("%d ",tmp[i][1]);		
		}
		if(tmp[i][0]<=n||tmp[i][1]<=n)printf("%d ",0);
	}
	return 0;
}