#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,m,q;
struct Point
{
	int x,y,id;
	bool operator <(const Point &b)const
		{return x==b.x?y<b.y:x<b.x;}
}a[MAXN];
bool cmp(Point a,Point b)
	{return a.y<b.y;}

int fa[MAXN],cnt;
bool visx[MAXN],visy[MAXN];
int getfa(int v)
	{return fa[v]==v?v:fa[v]=getfa(fa[v]);}

void merge(int u,int v)
{
	u=getfa(u);v=getfa(v);
	if(u==v)return;
	fa[u]=v;
	cnt++;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++)
    {
    	scanf("%d%d",&a[i].x,&a[i].y);
    	a[i].id=fa[i]=i;
    	visx[a[i].x]=visy[a[i].y]=1;
    }
    sort(a+1,a+q+1);
    for(int i=2;i<=q;i++)
    	if(a[i].x==a[i-1].x)merge(a[i].id,a[i-1].id);
    sort(a+1,a+q+1,cmp);
    for(int i=2;i<=q;i++)
    	if(a[i].y==a[i-1].y)merge(a[i].id,a[i-1].id);
    int tot1=0,tot2=0;
    for(int i=1;i<=n;i++)
    	if(!visx[i])tot1++;
    for(int i=1;i<=m;i++)
    	if(!visy[i])tot2++;
    cout<<tot1+tot2+q-cnt-1<<endl;
    return 0;
}