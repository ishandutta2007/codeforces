#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MAXN 10000
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
}points[MAXN],o;
int tot=0,n,r,m; //m=
inline int dist(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool cmp(Point a,Point b)
{
    return dist(a,o)>dist(b,o);
}
void init()
{
    scanf("%d%d",&n,&r);
    for(int i=-r;i<=r;i++)
        for(int j=-r;j<=r;j++)
            if(dist(Point(i,j),o)<=r*r)
                points[++tot]=Point(i,j);
    sort(points+1,points+tot+1,cmp);
    m=min(18,max(n,tot)); //!!!!18,rn(0,0)
}
int ans[MAXN],maxans;
int numofpoint[MAXN],stack[MAXN],top=0;
void DFS(int x,int used,int sum) //xusedsum
{
    if(used==n)
    {
        if(maxans<sum)
        {
            maxans=sum;
            memcpy(ans,stack,sizeof(stack));
        }
        return;
    }
    for(int i=x;i<=m;i++)
    {
        stack[++top]=i;
        int tmp=0;
        for(int j=1;j<top;j++)
            tmp+=dist(points[stack[j]],points[i]);
        DFS(i,used+1,sum+tmp);
        top--;
    }
}
int main()
{
	/*int T;
	scanf("%d",&T);
	while (T--)
	{*/
		maxans=0;
		top=0;
		tot=0;
		init();
	    DFS(1,0,0);
	    printf("%d\n",maxans);
	    for (int u=1;u<=n;u++)
	    	printf("%d %d\n",points[ans[u]].x,points[ans[u]].y);
	//}
    return 0;
}