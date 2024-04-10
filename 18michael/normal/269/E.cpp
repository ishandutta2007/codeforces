#include<bits/stdc++.h>
using namespace std;
int n,m,st_t,to_t=0,now;
char c1,c2;
int cnt[6],edge_t[2],X[100002],Y[100002];
int la[2][400002],to[800002][7],t[4][2];
bool vis[400002];
vector<int> Vec;
vector<vector<int> > vec[2][800002];
struct aaa
{
	int to,nx,val;
}edge[2][800002];
struct bbb
{
	int val,num;
}st[400002],st1[400002],tmp[400002];
inline int get(char x,char y)
{
	if(x>y)swap(x,y);
	if(x=='B')
	{
		if(y=='L')return 0;
		if(y=='R')return 1;
		return 2;
	}
	if(x=='L')
	{
		if(y=='R')return 3;
		return 4;
	}
	return 5;
}
inline int num(char c,int x)
{
	if(c=='B')return x;
	if(c=='L')return m+x;
	if(c=='R')return m+n+x;
	return m+n*2+x;
}
inline void add_edge(int x,int y,int z,int o)
{
	edge[o][++edge_t[o]]=(aaa){y,la[o][x],z},la[o][x]=edge_t[o];
	edge[o][++edge_t[o]]=(aaa){x,la[o][y],z},la[o][y]=edge_t[o];
}
inline void dfs(int x,int f,int o)
{
	vis[x]=1;
	for(int i=la[o][x],v;i;i=edge[o][i].nx)
		if((v=edge[o][i].to)!=f)
		{
			st[++st_t]=(bbb){edge[o][i].val,x};
			if(!vis[v])dfs(v,x,o);
			return ;
		}
}
inline void getmn(bbb a[])
{
	int i=0,j=1,k=0;
	while(i<=st_t && j<=st_t)
	{
		while(k<=st_t+1 && a[(i+k)%(st_t+1)].val==a[(j+k)%(st_t+1)].val)++k;
		if(a[(i+k)%(st_t+1)].val<a[(j+k)%(st_t+1)].val)swap(i,j);
		i+=k+1,i+=(i==j),k=0;
	}
	for(int l=0;l<=st_t;++l)tmp[l]=a[l];
	for(int l=0;l<=st_t;++l)a[l]=tmp[(l+j)%(st_t+1)];
}
inline void updmn(bbb a[],bbb b[])
{
	for(int i=0;i<=st_t;++i)
	{
		if(a[i].val<b[i].val)return ;
		if(a[i].val>b[i].val)
		{
			for(int j=i;j<=st_t;++j)a[j]=b[j];
			return ;
		}
	}
}
inline void ins(bbb a[],int o)
{
	now=0,Vec.clear();
	for(int i=0;i<=st_t;++i)
	{
		if(!to[now][a[i].val])to[now][a[i].val]=(++to_t);
		now=to[now][a[i].val],Vec.push_back(st[i].num);
	}
	vec[o][now].push_back(Vec);
}
inline bool dfs(int x)
{
	if(vec[0][x].size()^vec[1][x].size())return 1;
	for(int i=0;i<vec[0][x].size();++i)
		for(int j=0;j<vec[0][x][i].size();++j)
		{
			if(!(j&1) && (vec[1][x][i][j]<=m || vec[1][x][i][j]>2*n+m)^(vec[0][x][i][j]<=m || vec[0][x][i][j]>2*n+m))swap(vec[0][x][i][j],vec[0][x][i][j+1]);
			if(vec[1][x][i][j]<=m)X[vec[1][x][i][j]]=vec[0][x][i][j]<=m? vec[0][x][i][j]:vec[0][x][i][j]-2*n-m;
			else if(vec[1][x][i][j]<=n+m)Y[vec[1][x][i][j]-m]=vec[0][x][i][j]<=n+m? vec[0][x][i][j]-m:vec[0][x][i][j]-n-m;
			else if(vec[1][x][i][j]<=2*n+m)Y[vec[1][x][i][j]-n-m]=vec[0][x][i][j]<=n+m? vec[0][x][i][j]-m:vec[0][x][i][j]-n-m;
			else X[vec[1][x][i][j]-2*n-m]=vec[0][x][i][j]<=m? vec[0][x][i][j]:vec[0][x][i][j]-2*n-m;
		}
	for(int i=0;i<=6;++i)if(to[x][i] && dfs(to[x][i]))return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m),t[0][0]=t[1][0]=t[2][0]=t[3][0]=1,t[1][1]=t[2][1]=n,t[0][1]=t[3][1]=m;
	for(int i=1;i<=n;++i)add_edge(num('L',i),num('R',i),6,0),add_edge(num('L',i),num('R',i),6,1);
	for(int i=1;i<=m;++i)add_edge(num('B',i),num('T',i),6,0),add_edge(num('B',i),num('T',i),6,1);
	for(int i=1,x,y;i<=n+m;++i)
	{
		do c1=getchar();while(c1!='B' && c1!='L' && c1!='R' && c1!='T');
		do c2=getchar();while(c2!='B' && c2!='L' && c2!='R' && c2!='T');
		scanf("%d%d",&x,&y),++cnt[get(c1,c2)],add_edge(num(c1,x),num(c2,y),get(c1,c2),0);
	}
	if(cnt[2] && cnt[3])return 0&puts("No solution");
	for(int i=1;i<=cnt[0];++i)add_edge(num('B',t[0][0]),num('L',t[1][1]),0,1),++t[0][0],--t[1][1];
	for(int i=1;i<=cnt[1];++i)add_edge(num('B',t[0][1]),num('R',t[2][1]),1,1),--t[0][1],--t[2][1];
	for(int i=1;i<=cnt[4];++i)add_edge(num('L',t[1][0]),num('T',t[3][0]),4,1),++t[1][0],++t[3][0];
	for(int i=1;i<=cnt[5];++i)add_edge(num('R',t[2][0]),num('T',t[3][1]),5,1),++t[2][0],--t[3][1];
	for(int i=1;i<=cnt[2];++i)add_edge(num('B',t[0][0]),num('T',t[3][0]),2,1),++t[0][0],++t[3][0];
	for(int i=1;i<=cnt[3];++i)add_edge(num('L',t[1][0]),num('R',t[2][0]),3,1),++t[1][0],++t[2][0];
	for(int i=1;i<=(n+m)*2;++i)
		if(!vis[i])
		{
			st_t=-1,dfs(i,0,0);
			for(int i=0;i<=st_t;++i)st1[i].val=st[st_t-i].val,st1[i].num=st[(st_t+1-i)%(st_t+1)].num;
			getmn(st),getmn(st1),updmn(st,st1),ins(st,0);
		}
	for(int i=1;i<=(n+m)*2;++i)vis[i]=0;
	for(int i=1;i<=(n+m)*2;++i)
		if(!vis[i])
		{
			st_t=-1,dfs(i,0,1);
			for(int i=0;i<=st_t;++i)st1[i].val=st[st_t-i].val,st1[i].num=st[(st_t+1-i)%(st_t+1)].num;
			getmn(st),getmn(st1),updmn(st,st1),ins(st,1);
		}
	if(dfs(0))puts("No solution");
	else
	{
		for(int i=1;i<=n;++i)printf("%d%c",Y[i],i==n? '\n':' ');
		for(int i=1;i<=m;++i)printf("%d%c",X[i],i==m? '\n':' ');
	}
	return 0;
}