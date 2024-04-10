#include<bits/stdc++.h>
#define B 316
#define Mx 100000
using namespace std;
int n,m,ans;
int rt[32200002],siz[32200002],laz[322],mx[322];
inline int num(int x,int y)
{
	return x*Mx+y;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline int get(int x)
{
	getroot(num(0,x));
	return (rt[num(0,x)]+laz[(x-1)/B+1]-1)%Mx+1;
}
inline void maintain(int x,int y,int z)
{
	for(int i=x,t;i<=y;++i)
	{
		getroot(num(0,i));
		if((t=get(i)-z)>0)getroot(num(0,i)),getroot(num((i-1)/B+1,t-laz[(i-1)/B+1])),--siz[rt[num(0,i)]],++siz[rt[num(0,i)]=rt[num((i-1)/B+1,t-laz[(i-1)/B+1])]];
	}
	mx[(x-1)/B+1]=0;
	for(int i=((x-1)/B)*B+1;i<=((x-1)/B+1)*B;++i)mx[(x-1)/B+1]=max(mx[(x-1)/B+1],get(i)-laz[(x-1)/B+1]);
}
inline void solve(int x,int y,int z)
{
	for(int i=x;i<=y;++i)ans+=(get(i)==z);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=num((n-1)/B+1,Mx);++i)rt[i]=i;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++siz[rt[num(0,i)]=num((i-1)/B+1,x)],mx[(i-1)/B+1]=max(mx[(i-1)/B+1],x);
	for(int o,x,y,z;m--;)
	{
		scanf("%d%d%d%d",&o,&x,&y,&z);
		if(o==1)
		{
			if((x-1)/B==(y-1)/B)maintain(x,y,z);
			else
			{
				maintain(x,((x-1)/B+1)*B,z),maintain(((y-1)/B)*B+1,y,z);
				for(int i=(x-1)/B+2;i<=(y-1)/B;++i)
				{
					if((z<<1)<=mx[i]+laz[i])
					{
						for(int j=1-laz[i];j<=min(z-laz[i],mx[i]);++j)
						{
							getroot(num(i,j)),getroot(num(i,j+z));
							if(rt[rt[num(i,j)]]^rt[num(i,j+z)])siz[rt[num(i,j+z)]]+=siz[rt[num(i,j)]],rt[rt[num(i,j)]]=rt[num(i,j+z)];
						}
						laz[i]-=z;
					}
					else if(z<mx[i]+laz[i])
					{
						for(int j=z+1-laz[i];j<=mx[i];++j)
						{
							getroot(num(i,j)),getroot(num(i,j-z));
							if(rt[rt[num(i,j)]]^rt[num(i,j-z)])siz[rt[num(i,j-z)]]+=siz[rt[num(i,j)]],rt[rt[num(i,j)]]=rt[num(i,j-z)];
						}
						mx[i]=z-laz[i];
					}
				}
			}
		}
		else
		{
			ans=0;
			if((x-1)/B==(y-1)/B)solve(x,y,z);
			else
			{
				solve(x,((x-1)/B+1)*B,z),solve(((y-1)/B)*B+1,y,z);
				for(int i=(x-1)/B+2;i<=(y-1)/B;++i)if(z-laz[i]<=Mx)getroot(num(i,z-laz[i])),ans+=(rt[num(i,z-laz[i])]==num(i,z-laz[i])? siz[rt[num(i,z-laz[i])]]:0);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}