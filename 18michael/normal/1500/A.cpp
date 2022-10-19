#include<bits/stdc++.h>
#define Mx 2500000
using namespace std;
int n;
int a[200002],id[200002],pos[5000002]={},pos1[5000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=2,j,k;i<=n;++i)
	{
		j=id[i-1],k=id[i];
		if(pos[a[k]-a[j]+Mx])
		{
			if(pos[a[k]-a[j]+Mx]<i-1)
			{
				printf("YES\n%d %d %d %d",id[pos[a[k]-a[j]+Mx]-1],k,id[pos[a[k]-a[j]+Mx]],j);
				return 0;
			}
		}
		else pos[a[k]-a[j]+Mx]=i;
	}
	for(int i=0;i<=Mx;++i)pos[i]=pos[i+Mx]=0;
	for(int i=1,k,l;i<=n;++i)
		for(int j=n;j>i;--j)
		{
			k=id[i],l=id[j];
			if(pos[a[k]+a[l]])
			{
				if(pos[a[k]+a[l]]<i && pos1[a[k]+a[l]]>j)
				{
					printf("YES\n%d %d %d %d",id[pos[a[k]+a[l]]],id[pos1[a[k]+a[l]]],k,l);
					return 0;
				}
			}
			else pos[a[k]+a[l]]=i,pos1[a[k]+a[l]]=j;
		}
	return 0&puts("NO");
}