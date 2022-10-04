#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=4005;

int n;
ll ans=0;
struct Point
{
	int x,y,k;
	Point(){}
	Point(int x,int y):x(x),y(y),k(0){}
	Point(int x,int y,int k):x(x),y(y),k(k){}
	inline int scene()const
	{
		if(!x)return k*8+(y>0?4:8);
		if(!y)return k*8+(x>0?2:6); 
		if(x>0)return k*8+(y>0?3:1);
		return k*8+(y>0?5:7);
	}
	inline bool operator <(const Point &b)const
	{
		if(scene()<b.scene())return 1;
		if(scene()>b.scene())return 0;
		int ax=this->x,ay=this->y;
		int bx=b.x,by=b.y;
		return (ll)ay*bx<(ll)ax*by;
	}
	inline Point inv()const
	{
		if((scene()-1)%8>=4)return Point(-x,-y,k+1);
		return Point(-x,-y,k);
	}
}a[MAXN],t[MAXN];
inline ll C2(int x)
	{return (ll)x*(x-1)/2;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d%d",&a[i].x,&a[i].y);
    t[0]=Point(0,-1);
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    		if(j<i)t[j]=Point(a[j].x-a[i].x,a[j].y-a[i].y);
    		else if(j>i)t[j-1]=Point(a[j].x-a[i].x,a[j].y-a[i].y);
    	sort(t+1,t+n);
    	for(int j=n;j<=2*n-2;j++)
    		t[j]=Point(t[j-n+1].x,t[j-n+1].y,1);
    	int cur=0;
    	for(int i=1;i<n;i++)
    	{
    		while(cur<=2*n-3 && t[cur+1]<t[i].inv())++cur;
    		int u=cur-i;
    		ans+=C2(u)*C2(n-2-u);
    	}
    }
    cout<<ans/2<<endl;
    return 0;
}