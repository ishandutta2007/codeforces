#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=102;
struct ban
{
	int x,y,s;
};
bool operator<(const ban& a,const ban& b)
{
	if(a.x<b.x)
		return true;
	if(a.x>b.x)
		return false;
	return a.y<b.y;
}

int n,m,c;
int v[11][N][N];
vector<int> a[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0;i<n;++i)
	{
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		a[x][y].push_back(s);
	}
	for(int i=100;i>=1;--i)
	{
		for(int j=100;j>=1;--j)
		{
			for(int k=0;k<=c;++k)
			{
				int gum=0;
				for(int ii=i;ii<=100;++ii)
				{
					for(int kk=0;kk<a[ii][j].size();++kk)
						gum+=(a[ii][j][kk]+k)%(c+1);
				}
				for(int jj=j+1;jj<=100;++jj)
				{
					for(int kk=0;kk<a[i][jj].size();++kk)
						gum+=(a[i][jj][kk]+k)%(c+1);
				}
				v[k][i][j]=v[k][i+1][j+1]+gum;
			}
		}
	}
	for(int i=0;i<m;++i)
	{
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		int k=t%(c+1);
		printf("%d\n",v[k][x1][y1]-v[k][x1][y2+1]-v[k][x2+1][y1]+v[k][x2+1][y2+1]);
	}
//	system("pause");
	return 0;
}