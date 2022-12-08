#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct H
{
	int x,y,s;
	bool operator < (const H &c)const{return s<c.s;}
}p[10005];
bool a[105][105],b[105][105],vis[105][105];
int n,m,k,cnt,tot;
bool getc(){char c=getchar();while (c!='.'&&c!='*')c=getchar();return c=='.';}
void dfs(int x,int y){if(!a[x][y])return;a[x][y]=0;dfs(x+1,y);dfs(x,y+1);dfs(x-1,y);dfs(x,y-1);}
void work(int x,int y){if(!a[x][y])return;p[cnt].s++; a[x][y]=0;work(x+1,y);work(x,y+1);work(x,y-1);work(x-1,y);}
void fill(int x,int y){if(!b[x][y])return;b[x][y]=0;tot++;fill(x+1,y);fill(x,y+1);fill(x-1,y);fill(x,y-1);}
int main()
{
	scanf("%d%d%d",&n,&m,&k);// printf("%d %d %d\n",n,m,k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=b[i][j]=getc();
	for (int i=1;i<=n;i++)
		dfs(i,1),dfs(i,m);
	for (int i=1;i<=m;i++)
		dfs(1,i),dfs(n,i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]){
				cnt++; p[cnt].x=i; p[cnt].y=j;
				work(i,j);// printf("%d %d %d\n",p[cnt].x,p[cnt].y,p[cnt].s);
			}
	sort(p+1,p+1+cnt);
	for (int i=1;i<=cnt-k;i++)fill(p[i].x,p[i].y);
	printf("%d\n",tot);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (b[i][j])putchar('.');else putchar('*');
		puts("");
	}
}