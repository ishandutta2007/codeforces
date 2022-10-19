#include<bits/stdc++.h>
using namespace std;
int n,m,num,Test_num;
int cnt[100002];
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
		read(n),read(m);for(int i=1;i<=n;++i)cnt[i]=0;
		for(int i=1,x,y,z;i<=m;++i)read(x),read(y),read(z),++cnt[y];
		for(int i=1;i<=n;++i)if(!cnt[i]){num=i;break;}
		for(int i=1;i<=n;++i)if(i!=num)printf("%d %d\n",i,num);
	}
	return 0;
}