#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

int half(LL x,LL y)
{
	return x>0 || x==0 & y>0;
}

struct point
{
	LL x,y;
	point(){}
	point(LL x_,LL y_){x=x_;y=y_;}
	bool operator<(const point &a) const
	{
		int h=half(x,y);
		int ah=half(a.x,a.y);
		if(h!=ah) return h>ah;
		return LL(x)*a.y>LL(a.x)*y;
	}
	bool operator==(const point &a) const
	{
		return half(x,y)==half(a.x,a.y) && x*a.y==a.x*y;
	}
};

#define N 155555
LL x[N],y[N];
point a[N];

int main()
{
#ifdef XDEBUG
	freopen("e.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		LL sx=0,sy=0;
		int i,j,k;
		int m=0;
		for(j=0;j<3;j++)
		{
			if(j) scanf("%d",&n);
			int mini=0;
			for(i=0;i<n;i++)
			{
				scanf("%I64d%I64d",x+i,y+i);
				if(mp(x[mini],y[mini])>mp(x[i],y[i]))
					mini=i;
			}
			sx+=x[mini];
			sy+=y[mini];
			for(i=0;i<n;i++)
				a[m++]=point(x[(i+1)%n]-x[i],y[(i+1)%n]-y[i]);
		}
		sort(a,a+m);
		for(i=k=0;i<m;i=j)
		{
			LL ax=0,ay=0;
			for(j=i;j<m && a[i]==a[j];j++)
				ax+=a[j].x,ay+=a[j].y;
			a[k++]=point(ax,ay);
		}
		m=k;
		x[0]=sx,y[0]=sy;
		for(i=0;i<m-1;i++)
		{
			x[i+1]=x[i]+a[i].x;
			y[i+1]=y[i]+a[i].y;
		}
		//for(i=0;i<m;i++) printf("%I64d %I64d\n",x[i],y[i]);
		int q;
		for(scanf("%d",&q);q--;)
		{
			LL u,v;
			scanf("%I64d%I64d",&u,&v);
			u*=3;
			v*=3;
			//u=5,v=1;
			if(u<sx || u==sx && v<sy){puts("NO");continue;}
			if(u==sx && v==sy){puts("YES"); continue;}
			if((u-sx)*(y[m-1]-sy)<(v-sy)*(x[m-1]-sx)){puts("NO");continue;}
			if((u-sx)*(y[m-1]-sy)==(v-sy)*(x[m-1]-sx))
			{
				puts(x[0]<x[m-1] && u<=x[m-1] || x[0]==x[m-1] && v<=y[m-1]?"YES":"NO");
				continue;
			}
			if((u-sx)*(y[1]-sy)>(v-sy)*(x[1]-sx)){puts("NO");continue;}
			if((u-sx)*(y[1]-sy)==(v-sy)*(x[1]-sx))
			{
				puts(u<=x[1]?"YES":"NO");
				continue;
			}
			int L=0;
			int R=m;
			while(L+1<R)
			{
				int M=(L+R)/2;
				LL vect=LL(u-sx)*(y[M]-sy)-LL(v-sy)*(x[M]-sx);
				if(vect<=0) L=M; else R=M;
			}
			if(0<L && R<m)
			{
				LL vect=LL(x[R]-u)*(y[L]-v)-LL(y[R]-v)*(x[L]-u);
				puts(vect>0?"NO":"YES");
			}
		}
	}
	return 0;
}