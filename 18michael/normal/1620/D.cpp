#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
int a[102],mx[3];
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
		read(n);
		for(int i=0;i<3;++i)mx[i]=0;
		for(int i=1;i<=n;++i)read(a[i]),mx[a[i]%3]=max(mx[a[i]%3],a[i]);
		sort(a+1,a+n+1);
		if(a[1]==1)
		{
			if(mx[2])printf("%d\n",max(max((mx[1]-1)/3,(mx[2]-2)/3),(mx[0]-3)/3)+2);
			else printf("%d\n",max((mx[1]-1)/3,mx[0]/3)+1);
		}
		else
		{
			if(mx[1] && mx[2])printf("%d\n",min(max(max((mx[1]-4)/3,(mx[2]-2)/3),mx[0]/3)+2,max(max((mx[1]-1)/3,(mx[2]-2)/3),(mx[0]-3)/3)+2));
			else if(mx[1] || mx[2])printf("%d\n",max(max((mx[1]-1)/3,(mx[2]-2)/3),mx[0]/3)+1);
			else printf("%d\n",mx[0]/3);
		}
	}
	return 0;
}