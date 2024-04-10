#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
struct ban
{
	int x,y;
};
const int N=1002;
int n,m;
char a[N][N];
int c[N][N];
int ans[N*N];
ban t;
int xx[4]={0,1,-1,0};
int yy[4]={1,0,0,-1};
void alik(int x,int y,int g)
{
	int i,j,k;
	queue<ban> q;
	t.x=x;
	t.y=y;
	c[x][y]=g;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;++i)
		{
			ban h;
			h.x=t.x+xx[i];
			h.y=t.y+yy[i];
			if(h.x>=0 && h.x<n && h.y>=0 && h.y<m)
			{
				if(a[h.x][h.y]=='*')
				{
					ans[g]++;
				}
				if(a[h.x][h.y]=='.' && !c[h.x][h.y])
				{
					c[h.x][h.y]=g;
					q.push(h);
				}
			}
		}
	}
}
int main()
{
	int i,j,k,cq=0,x,y;
	cin>>n>>m>>k;
	for(i=0;i<n;++i)
		scanf("%s",&a[i]);
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]=='.' && !c[i][j])
			{
				++cq;
				alik(i,j,cq);
			}
		}
	}
	for(i=0;i<k;++i)
	{
		cin>>x>>y;
		--x;
		--y;
		cout<<ans[c[x][y]]<<endl;
	}
	return 0;
}