#include <iostream>
#include <vector>
using namespace std;
struct ban
{
	char col;
	int x,y;
};
const int N=505;
char a[N][N];
int n,m,k;
int px[4]={0,1,0,-1};
int py[4]={1,0,-1,0};
bool c[N][N];
vector<ban> ans;
void avel(char co,int x,int y)
{
	ban z;
	z.col=co;
	z.x=x;
	z.y=y;
	ans.push_back(z);
}
void dfs(int x,int y,bool t)
{
	int hx,hy,i;
	c[x][y]=true;
	avel('B',x,y);
	for(i=0;i<4;i++)
	{
		hx=x+px[i];
		hy=y+py[i];
		if(!c[hx][hy] && a[hx][hy]=='.')
		{
			dfs(hx,hy,false);
		}
	}
	if(!t)
	{
		avel('D',x,y);
		avel('R',x,y);
	}
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!c[i][j] && a[i][j]=='.')
			{
				dfs(i,j,true);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
	{
		printf("%C ",ans[i].col);
		printf("%d ",ans[i].x+1);
		printf("%d\n",ans[i].y+1);
	}
	return 0;
}