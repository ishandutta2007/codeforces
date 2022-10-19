#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,k,res,l,r,Test_num;
int a[200002],cnt[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k),res=0,l=1,r=n;
		for(int i=1;i<=n;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]];
		for(int i=1,j=0;i<=n;++i)
		{
			while(j<n && 2*res<n+k)res+=cnt[++j];
			if(2*res>=n+k && j-i<r-l)l=i,r=j;
			res-=cnt[i];
		}
		res=0,printf("%d %d\n",l,r);
		for(int i=1,j=1;i<=n;++i)
			if((res+=((a[i]>=l && a[i]<=r)? 1:-1))>0)
			{
				if(k==1)
				{
					printf("%d %d\n",j,n);
					break;
				}
				printf("%d %d\n",j,i),j=i+1,--k,res=0;
			}
	}
	return 0;
}