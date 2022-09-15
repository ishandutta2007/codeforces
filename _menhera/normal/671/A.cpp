#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int x[101010];
int y[101010];
double dist[101010][2];
double tdist[101010];
double minv[2] = {1e10,1e10};
int mini[2] = {1, 1};
int main()
{
	int ax, ay, bx, by, tx, ty;
	int N;
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d%d",x+i, y+i);
		dist[i][0] = hypot(ax-x[i], ay-y[i]);
		dist[i][1] = hypot(bx-x[i], by-y[i]);
		tdist[i] = hypot(tx-x[i], ty-y[i]);
	}
	//x chooses all
	double totv = 0;
	for(int i=0; i<N; i++)
		totv += 2*tdist[i];
	double ans = 1e20;
	for(int x=0; x<2; x++)
	{
		for(int i=0; i<N; i++)
		{
			if(minv[x]>dist[i][x]-tdist[i])
			{
				minv[x] = dist[i][x]-tdist[i];
				mini[x] = i;
			}
		}
		ans = min(ans, totv+minv[x]);
	}
	for(int x=0; x<2; x++)
	{
		double minvs=1e10;
		for(int i=0; i<N; i++)
		{
			if(mini[1-x]==i) continue;
			minvs = min(minvs,dist[i][x]-tdist[i]); 
		}
		ans = min(ans, totv+minv[1-x]+minvs);
	}
	printf("%.12lf",ans);
}