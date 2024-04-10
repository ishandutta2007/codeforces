#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200003;

int n, m;
int a[N];
int t[N*4];
void build(int tl,int tr,int pos,int x)
{
	if(tl==tr)
	{
		t[pos]=a[tl];
		return;
	}
	int mid=(tl+tr)/2;
	build(tl,mid,pos*2,x+1);
	build(mid+1,tr,pos*2+1,x+1);
	if(n%2==0)
	{
		///or
		if(x%2==0)
		{
			t[pos]=t[pos*2] | t[pos*2+1];
		}
		//xor
		else
		{
			t[pos]=t[pos*2] ^ t[pos*2+1];
		}
	}
	else
	{
		///or
		if(x%2==1)
		{
			t[pos]=t[pos*2] | t[pos*2+1];
		}
		//xor
		else
		{
			t[pos]=t[pos*2] ^ t[pos*2+1];
		}
	}
}
void ubd(int tl,int tr,int i,int y,int pos,int x)
{
	if(tl==tr)
	{
		t[pos]=y;
		return;
	}
	int mid=(tl+tr)/2;
	if(i<=mid)
		ubd(tl,mid,i,y,pos*2,x+1);
	else
		ubd(mid+1,tr,i,y,pos*2+1,x+1);
	if(n%2==0)
	{
		///or
		if(x%2==0)
		{
			t[pos]=t[pos*2] | t[pos*2+1];
		}
		//xor
		else
		{
			t[pos]=t[pos*2] ^ t[pos*2+1];
		}
	}
	else
	{
		///or
		if(x%2==1)
		{
			t[pos]=t[pos*2] | t[pos*2+1];
		}
		//xor
		else
		{
			t[pos]=t[pos*2] ^ t[pos*2+1];
		}
	}
}
int main()
{
	///in
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(1<<n);++i)
	{
		scanf("%d",&a[i]);
	}
	/////
	build(1,(1<<n),1,1);
	/////
	for(int ii=0;ii<m;++ii)
	{
		int i,y;
		scanf("%d%d",&i,&y);
		ubd(1,(1<<n),i,y,1,1);
		printf("%d\n",t[1]);
	}
//	system("pause");
	return 0;
}