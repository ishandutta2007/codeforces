#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,w,h;
struct Dancer
{
	int g,p,t,id;
	inline bool operator <(const Dancer &b)const{return p-t<b.p-b.t;}
}a[MAXN];
int t1[MAXN],t2[MAXN];
inline bool cmp1(int x,int y)
{
	if(a[x].g!=a[y].g)return a[x].g>a[y].g;
	return a[x].g==1?a[x].p<a[y].p:a[x].p>a[y].p;
}
inline bool cmp2(int x,int y)
{
	if(a[x].g!=a[y].g)return a[x].g<a[y].g;
	return a[x].g==1?a[x].p<a[y].p:a[x].p>a[y].p;
}

int d[MAXN],dg[MAXN];
void work(int l,int r)
{
	for(int i=l;i<=r;i++)t1[i]=t2[i]=i;
	sort(t1+l,t1+r+1,cmp1);sort(t2+l,t2+r+1,cmp2);
	for(int i=l;i<=r;i++)
	{
		d[a[t1[i]].id]=a[t2[i]].p;
		dg[a[t1[i]].id]=a[t2[i]].g;
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d%d",&a[i].g,&a[i].p,&a[i].t);
    	a[i].id=i;
    }
    sort(a+1,a+n+1);
    int last=1;
    for(int i=2;i<=n+1;i++)
    	if(i==n+1 || a[i].p-a[i].t!=a[i-1].p-a[i-1].t)
			{work(last,i-1);last=i;}
	for(int i=1;i<=n;i++)
		if(dg[i]==1)printf("%d %d\n",d[i],h);
		else printf("%d %d\n",w,d[i]);
    return 0;
}