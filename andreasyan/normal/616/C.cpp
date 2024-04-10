#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1003;
struct ban
{
	int x,y;
};

char a[N][N];
int c[N][N],b[N*N];
int n,m;
ban t;
int x[4]={0,1,-1,0};
int y[4]={1,0,0,-1};
char ans[N][N];
void aliq(int xx,int yy,int ch)
{
	int i,j,k,res=0;
	t.x=xx;
	t.y=yy;
	queue<ban> q;
	c[xx][yy]=ch;
	q.push(t);
	while(!q.empty())
	{
		++res;
		t=q.front();
		q.pop();
		for(i=0;i<4;++i)
		{
			ban h=t;
			h.x+=x[i];
			h.y+=y[i];
			if(h.x>=0 && h.x<n && h.y>=0 && h.y<m && a[h.x][h.y]=='.' && c[h.x][h.y]==0)
			{
				c[h.x][h.y]=ch;
				q.push(h);
			}
		}
	}
	b[ch]=res;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
		scanf("%s",a[i]);
	k=1;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]=='.' && c[i][j]==0)
			{
				aliq(i,j,k);
				++k;
			}
		}
	}
	//
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]=='.')
			{
				ans[i][j]='.';
				continue;
			}
			int yans=1;
			map<int,bool> mp;
			for(k=0;k<4;++k)
			{
				ban h;
				h.x=i;
				h.y=j;
				h.x+=x[k];
				h.y+=y[k];
				if(h.x>=0 && h.x<n && h.y>=0 && h.y<m && !mp[c[h.x][h.y]])
				{
					mp[c[h.x][h.y]]=true;
					yans+=b[c[h.x][h.y]];
				}
			}
			ans[i][j]=(yans%10)+'0';
		}
	}
	for(i=0;i<n;++i)
		printf("%s\n",ans[i]);
	return 0;
}