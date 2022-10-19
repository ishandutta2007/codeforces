#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005,mm=1000*1000*1000+1;
struct ban
{
	int x,y,k;
};

int n;
int a[N],b[N];
int t[N*4];
void sift(int pos)
{
	t[pos*2]=t[pos];
	t[pos*2+1]=t[pos];
	t[pos]=-1;
}
void ubd(int tl,int tr,int l,int r,int h,int pos)
{
	if(tl==l && tr==r)
	{
		t[pos] = h;
		return;
	}
	int m=(tl+tr)/2;
	if(t[pos]!=-1)
		sift(pos);
	if(r<=m)
		ubd(tl,m,l,r,h,pos*2);
	else if(l>m)
		ubd(m+1,tr,l,r,h,pos*2+1);
	else
	{
		ubd(tl,m,l,m,h,pos*2);
		ubd(m+1,tr,m+1,r,h,pos*2+1);
	}
}
int get(int tl,int tr,int x,int pos)
{
	if(tl==tr)
	{
		return t[pos];
	}
	int m=(tl+tr)/2;
	if(t[pos]!=-1)
		sift(pos);
	if(x<=m)
		return get(tl,m,x,pos*2);
	else
		return get(m+1,tr,x,pos*2+1);
}
int main()
{
	int m;
	ban q[N];
	///in
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&b[i]);
	/////
	for(int i=1;i<=m;++i)
	{
		int u;
		scanf("%d",&u);
		if(u==2)
		{
			scanf("%d",&q[i].x);
			q[i].x--;
			int ans;
			u=get(0,n-1,q[i].x,1);
			if(u==0)
			{
				printf("%d\n",b[q[i].x]);
			}
			else
			{
				printf("%d\n",a[(q[u].x-q[u].y)+q[i].x]);
			}
		}
		else
		{
			scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].k);
			--q[i].x;
			--q[i].y;
			ubd(0,n-1,q[i].y,q[i].y+q[i].k-1,i,1);
		}
	}
//	system("pause");
	return 0;
}