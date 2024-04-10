#include<bits/stdc++.h>
using namespace std;
int Test_num,n,ans;
struct aaa
{
	int x,y;
}p[200002],q[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.x<b.x? 1:0;
}
int main()
{
	read(Test_num),p[0].x=p[0].y=1;
	while(Test_num--)
	{
		read(n),ans=0;
		for(int i=1;i<=n;++i)read(p[i].x);
		for(int i=1;i<=n;++i)read(p[i].y);
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;++i)q[i].x=p[i].x-p[i-1].x,q[i].y=p[i].y-p[i-1].y;
		for(int i=1;i<=n;++i)
		{
			if((p[i-1].x+p[i-1].y)&1)q[i].x-=q[i].y,ans+=(q[i].x+1)/2;
			else
			{
				if(q[i].x==q[i].y)ans+=q[i].x;
				else q[i].x-=q[i].y,ans+=q[i].x/2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}