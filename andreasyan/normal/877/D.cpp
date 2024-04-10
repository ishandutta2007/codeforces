#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=1002;
struct ban
{
	int x,y;
};

char a[N][N];
int c[N][N];
ban s,v;
int n,m,k;
int xx[4]={0,1,-1,0};
int yy[4]={1,0,0,-1};
void bfs()
{
	ban t;
	queue<ban> q;
	c[s.x][s.y]=1;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		/////
		if(t.x==v.x && t.y==v.y)
			return;
		for(int j=0;j<4;++j)
		{
			for(int i=1;i<=k;++i)
			{
				ban h;
				h=t;
				h.x+=(xx[j]*i);
				h.y+=(yy[j]*i);
				/////
				if(a[h.x][h.y]!='.' || !(h.x>=0) || !(h.x<n) || !(h.y>=0) || !(h.y<m))
					break;
				if(c[h.x][h.y]<=c[t.x][t.y] && c[h.x][h.y])
					break;
				if(c[h.x][h.y]>c[t.x][t.y]+1 || !c[h.x][h.y])
				{
					c[h.x][h.y]=c[t.x][t.y]+1;
					q.push(h);
				}
			}
		}
	}
}
int main()
{
	///in
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i)
		scanf("%s",&a[i]);
	scanf("%d%d%d%d",&s.x,&s.y,&v.x,&v.y);
	--s.x;
	--s.y;
	--v.x;
	--v.y;
	/////
	bfs();
	//out
	printf("%d\n",c[v.x][v.y]-1);
//	system("pause");
	return 0;
}