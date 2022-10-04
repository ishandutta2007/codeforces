#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=200005,INF=1<<30;
const double eps=1e-12;

int n,m;
inline int dcmp(double x)
{
	if(x>eps)return 1;
	return x<-eps?-1:0;
}

struct Data
{
	double a,b;
	bool operator <(const Data &c)const
		{return b<c.b;}
}d[MAXN];

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    double ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%lf",&d[i].a);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lf",&d[i].b);
    	d[i].b-=m;
    	if(!dcmp(d[i].b))ans+=d[i].a;
    }
    sort(d+1,d+n+1);
	int l=0,r=n+1;
    for(int i=1;i<=n;i++)
    	if(dcmp(d[i].b)>0)
    	{
    		r=i;
    		break;
    	}
    for(int i=n;i>0;i--)
    	if(dcmp(d[i].b)<0)
    	{
    		l=i;
    		break;
    	}

    while(l>0 && r<=n)
    {
    	if(-d[l].a*d[l].b<d[r].a*d[r].b)
    	{
    		ans+=d[l].a-d[l].a*d[l].b/d[r].b;
    		d[r].a+=d[l].a*d[l].b/d[r].b;
    		l--;
    		//cout<<"L"<<ans<<endl;
    	}
    	else
    	{
    		ans+=d[r].a-d[r].a*d[r].b/d[l].b;
    		d[l].a+=d[r].a*d[r].b/d[l].b;
    		r++;
    		//cout<<"R"<<ans<<endl;
    	}
    }
    printf("%.12lf\n",ans);
    return 0;
}