#include<cstdio>
#include<cstring>
#include<algorithm>
#define retrun return
#define cpnst const
#define inlien inline
#define reply fflush(stdout)
typedef long long ll;
typedef double db;
inline int min(int x,int y)
{return(x<y)?x:y;}
inline int max(int x,int y)
{return(x>y)?x:y;}
int n,q;
int a[1111111];
bool v[3][333333];
ll tot;
void exec()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=(x==1?2:1);
		if(v[x][y]==1)
		{
			if(v[xx][y])tot--;
			if(v[xx][y-1])tot--;
			if(v[xx][y+1])tot--;
		}
		else
		{
			if(v[xx][y])tot++;
			if(v[xx][y-1])tot++;
			if(v[xx][y+1])tot++;
		}
		if(!tot)puts("Yes");
		else puts("No");
		v[x][y]=!v[x][y];
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/