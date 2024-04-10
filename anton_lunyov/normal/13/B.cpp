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

#define X first
#define Y second

int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	for(scanf("%d",&T);T--;)
	{
		PII a[3][2];
		int i,j,i1,j1;
		int i_=0,j_=0,i1_=0,j1_=0;
		for(i=0;i<3;i++)
		{
			scanf("%d%d%d%d",&a[i][0].X,&a[i][0].Y,&a[i][1].X,&a[i][1].Y);
			for(j=0;j<i;j++)
				for(i1=0;i1<2;i1++)
					for(j1=0;j1<2;j1++)
						if(a[i][i1]==a[j][j1]) i_=i,j_=j,i1_=i1,j1_=j1;
		}
		if(i_==j_){puts("NO");continue;}
		int k_;
		for(k_=0;k_<3 && (k_==i_ || k_==j_);k_++);
		if(i1_) swap(a[i_][0],a[i_][1]);
		if(j1_) swap(a[j_][0],a[j_][1]);
		LL x=a[i_][0].X,y=a[i_][0].Y;
		for(i=0;i<3;i++)
			for(i1=0;i1<2;i1++) a[i][i1].X-=x,a[i][i1].Y-=y;
		LL x1=a[i_][1].X,y1=a[i_][1].Y;
		LL x2=a[j_][1].X,y2=a[j_][1].Y;
		LL x3=a[k_][0].X,y3=a[k_][0].Y;
		LL x4=a[k_][1].X,y4=a[k_][1].Y;
		LL scal=x1*x2+y1*y2;
		LL vect=x1*y2-x2*y1;
		if(scal<0 || vect==0){puts("NO");continue;}
		if(x1*y3!=x3*y1) swap(x3,x4),swap(y3,y4);
		if(x1*y3!=x3*y1 || x2*y4!=x4*y2){puts("NO");continue;}
		LL d30=sqr(x3)+sqr(y3);
		LL d31=sqr(x3-x1)+sqr(y3-y1);
		LL d1=sqr(x1)+sqr(y1);
		if(25*d30<d1 || 25*d31<d1 || d30>d1 || d31>d1){puts("NO");continue;}
		LL d40=sqr(x4)+sqr(y4);
		LL d42=sqr(x4-x2)+sqr(y4-y2);
		LL d2=sqr(x2)+sqr(y2);
		if(25*d40<d2 || 25*d42<d2 || d40>d2 || d42>d2){puts("NO");continue;}
		puts("YES");
	}
	return 0;
}