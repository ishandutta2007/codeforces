#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

struct point
{
	LL x,y;
	int col;
	point(){}
	point(LL x_,LL y_,int col_){x=x_,y=y_,col=col_;}
	bool operator<(const point &a) const
	{
		int h=y>0 || (y==0 && x>0);
		int ah=a.y>0 || (a.y==0 && a.x>0);
		if(h!=ah) return h<ah;
		return x*a.y>y*a.x;
	}
};

#define N 1111
point a[N],b[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n1,n;
	while(scanf("%d%d",&n1,&n)>0)
	{
		n+=n1;
		int i,j,k,h,j1;
		for(i=0;i<n;i++)
		{
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
			a[i].col=i<n1;
		}
		int ans=0;
		for(i=0;i<n1;i++)
		{
			k=0;
			for(j=i+1;j<n;j++)
				b[k++]=point(a[j].x-a[i].x,a[j].y-a[i].y,a[j].col);
			sort(b,b+k);
			//for(j=0;j<k;j++) printf("%I64d %I64d %d\n",b[j].x,b[j].y,b[j].col);
			for(j=j1=0;j<k;j++)
			{
				LL x=b[j].x;
				LL y=b[j].y;
				if(j1==j) j1=(j+1)%k;
				for(;x*b[j1].y>y*b[j1].x;j1=(j1+1)%k);
				if(b[j].col)
				{
					LL bx=0,by=0;
					for(h=(j+1)%k;h!=j1;)
					{
						if(!b[h].col)
						{
							if(bx*(b[h].y-y)>=by*(b[h].x-x)) bx=b[h].x-x,by=b[h].y-y;
						}
						else
						{
							if(bx*(b[h].y-y)>=by*(b[h].x-x)) ans++;
						}
						++h;
						if(h==k) h=0;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}