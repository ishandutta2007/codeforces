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

#define N 555

struct Ipoint
{
	int x,y;
	Ipoint(){}
	Ipoint(int x_,int y_){x=x_;y=y_;}
};

struct Dpoint
{
	double x,y;
	Dpoint(){}
	Dpoint(double x_,double y_){x=x_;y=y_;}
	bool operator<(const Dpoint &p) const
	{
		double v=x*p.y-y*p.x;
		return v<0;
	}
};

Dpoint operator-(const Dpoint &a,const Dpoint &b)
{
	return Dpoint(a.x-b.x,a.y-b.y);
}

double vect(const Dpoint &a,const Dpoint &b)
{
	return a.x*b.y-a.y*b.x;
}

bool inter(const Ipoint &p1,const Ipoint &p2,const Ipoint &p3,const Ipoint &p4,Dpoint &p)
{
	int x1=p1.x,y1=p1.y;
	int x2=p2.x,y2=p2.y;
	int x3=p3.x,y3=p3.y;
	int x4=p4.x,y4=p4.y;
	LL d =LL(x2-x1)*(y3-y4)-LL(y2-y1)*(x3-x4);
	LL dt=LL(x3-x1)*(y3-y4)-LL(y3-y1)*(x3-x4);
	LL ds=LL(x2-x1)*(y3-y1)-LL(y2-y1)*(x3-x1);
	if(d<0) d=-d,dt=-dt,ds=-ds;
	if(d==0) return false;
	if(0<=dt && dt<=d && 0<=ds && ds<=d)
	{
		double t=1.*dt/d;
		p.x=p1.x+t*(p2.x-p1.x);
		p.y=p1.y+t*(p2.y-p1.y);
		return true;
	}
	return false;
}

int main()
{
#ifdef MY_DEBUG
	freopen("e.in","r",stdin);
#endif
	int n;
	int h,f;
	while(scanf("%d%d%d",&n,&h,&f)>0)
	{
		int i,j,k;
		Ipoint a[N][4];
		Ipoint b[N][4];
		double ans=0;
		for(i=0;i<n;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);

			a[i][0]=Ipoint((f-h)*l,1);
			a[i][1]=Ipoint((f-h)*r,1);
			a[i][2]=Ipoint((f+h)*l,-1);
			a[i][3]=Ipoint((f+h)*r,-1);

			b[i][0]=Ipoint((f-h)*l,-1);
			b[i][1]=Ipoint((f-h)*r,-1);
			b[i][2]=Ipoint((f+h)*l,1);
			b[i][3]=Ipoint((f+h)*r,1);

			ans+=8.*f*(r-l);
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				vector<Dpoint> c;
				Dpoint p;
				if(inter(a[i][0],a[i][2],b[j][0],b[j][2],p))
					c.pb(p);
				if(inter(a[i][0],a[i][2],b[j][1],b[j][3],p))
					c.pb(p);
				if(inter(a[i][1],a[i][3],b[j][0],b[j][2],p))
					c.pb(p);
				if(inter(a[i][1],a[i][3],b[j][1],b[j][3],p))
					c.pb(p);
				if(a[i][0].x<b[j][3].x && b[j][2].x<a[i][1].x)
				{
					p.x=max(a[i][0].x,b[j][2].x);
					p.y=1;
					c.pb(p);

					p.x=min(a[i][1].x,b[j][3].x);
					p.y=1;
					c.pb(p);
				}
				if(a[i][2].x<b[j][1].x && b[j][0].x<a[i][3].x)
				{
					p.x=max(a[i][2].x,b[j][0].x);
					p.y=-1;
					c.pb(p);

					p.x=min(a[i][3].x,b[j][1].x);
					p.y=-1;
					c.pb(p);
				}
				if(c.sz)
				{
					int mink=0;
					for(k=0;k<c.sz;k++)
						if(c[mink].x>c[k].x || c[mink].x==c[k].x && c[mink].y>c[k].y)
							mink=k;
					if(mink!=0) swap(c[0],c[mink]);
					Dpoint d[11];
					int m=0;
					for(k=0;k<c.sz;k++)
						d[m++]=c[k]-c[0];
					sort(d+1,d+m);
					Dpoint e[11]={d[0],d[1]};
					int q=1;
					for(k=2;k<m;k++)
					{
						for(;q && vect(d[k]-e[q],e[q]-e[q-1])<0;q--)
							;
						e[++q]=d[k];
					}
					q++;
					double cur=0;
					for(k=0;k<q;k++)
						cur+=vect(e[k],e[(k+1)%q]);
					cur=fabs(cur);
					ans-=cur;
				}
			}
		ans/=2.*(f-h)/h;
		printf("%.7lf\n",ans);
	}
	return 0;
}