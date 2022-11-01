#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define MP(A,B) make_pair(A,B)
typedef long long int64;

const int maxn=500+5;

int64 cross(int64 x0,int64 y0,int64 x1,int64 y1,int64 x2,int64 y2)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
int main()
{
#ifdef _MSC_VER
/*
	freopen("input.txt","w",stdout);
	printf("%d %d\n",5,5);
	for (int i=0;i<10;i++)
		printf("%d %d\n",rand(),rand());
	return 0;
*/
	freopen("input.txt","r",stdin);
#endif
	int n,m;
	int x1[maxn],y1[maxn],x2[maxn],y2[maxn];
	int c1,c2;
	pair<double,int> p1[maxn],p2[maxn];
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d%d",&x1[i],&y1[i]);
	for (int i=0;i<m;i++) scanf("%d%d",&x2[i],&y2[i]);
	if (n<3)
	{
		printf("0\n");
		return 0;
	}
	int R=0;
	for (int k=0;k<n;k++)
	{
		int cx=x1[k],cy=y1[k];
		c1=c2=0;
		for (int i=0;i<n;i++) if (y1[i]>cy || y1[i]==cy && x1[i]>cx) p1[c1++]=MP(atan2((double)y1[i]-cy,x1[i]-cx),i);
		for (int i=0;i<m;i++) if (y2[i]>cy || y2[i]==cy && x2[i]>cx) p2[c2++]=MP(atan2((double)y2[i]-cy,x2[i]-cx),i);
		sort(p1,p1+c1);
		sort(p2,p2+c2);
		for (int i=0;i<c1;i++)
		{
			int key=p1[i].second;
			int last=0,pk=-1;
			for (;last<c2 && p2[last].first<p1[i].first;last++);
			for (int j=i+1;j<c1;j++)
			{
				int other=p1[j].second;
				for (;last<c2 && p2[last].first<p1[j].first;last++) 
				{
					int pk2=p2[last].second;
					if (pk<0 || cross(x1[key],y1[key],x2[pk],y2[pk],x2[pk2],y2[pk2])>0)
						pk=pk2;
				}
				if (pk<0 || cross(x1[key],y1[key],x1[other],y1[other],x2[pk],y2[pk])<0)
					R++;
			}
		}
	}
	printf("%d\n",R);
	return 0;
}