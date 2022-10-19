#include<bits/stdc++.h>
using namespace std;
int n,m,t,l,r,Test_num;
int at[300002],nt[300002];
char bt[300002];
struct aaa
{
	int a,id,ans;
	char b;
}p[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.a<b.a? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return a.id<b.id? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=1;i<=n;++i)read(p[i].a),p[i].ans=-1,p[i].id=i;
		for(int i=1;i<=n;++i)do p[i].b=getchar();while(p[i].b!='L' && p[i].b!='R');
		sort(p+1,p+n+1,cmp),t=0;
		//for(int i=1;i<=n;++i)printf("%d%c",p[i].a,i==n? '\n':' ');
		//for(int i=1;i<=n;++i)printf("%c%c",p[i].b,i==n? '\n':' ');
		for(int i=1;i<=n;++i)
			if(p[i].a&1)
			{
				at[++t]=p[i].a,bt[t]=p[i].b,nt[t]=i;
				if(t>1 && bt[t-1]=='R' && bt[t]=='L')
					p[nt[t-1]].ans=p[nt[t]].ans=(at[t]-at[t-1])/2,t-=2;
			}
		//for(int i=1;i<=n;++i)printf("   %d%c",p[i].ans,i==n? '\n':' ');
		for(l=1;l<t;l+=2)
		{
			if(bt[l]=='L' && bt[l+1]=='L')p[nt[l]].ans=p[nt[l+1]].ans=(at[l+1]+at[l])/2;
			else break;
		}
		for(r=t;r>1;r-=2)
		{
			if(bt[r]=='R' && bt[r-1]=='R')p[nt[r]].ans=p[nt[r-1]].ans=(m-at[r-1]+m-at[r])/2;
			else break;
		}
		//printf("l:%d r:%d\n",l,r);
		if(l<r)p[nt[l]].ans=p[nt[r]].ans=(at[l]+m-at[r]+m)/2;
		//for(int i=1;i<=n;++i)printf("   %d%c",p[i].ans,i==n? '\n':' ');
		t=0;
		for(int i=1;i<=n;++i)
			if(!(p[i].a&1))
			{
				at[++t]=p[i].a,bt[t]=p[i].b,nt[t]=i;
				if(t>1 && bt[t-1]=='R' && bt[t]=='L')
					p[nt[t-1]].ans=p[nt[t]].ans=(at[t]-at[t-1])/2,t-=2;
			}
		//for(int i=1;i<=n;++i)printf("   %d%c",p[i].ans,i==n? '\n':' ');
		for(l=1;l<t;l+=2)
		{
			if(bt[l]=='L' && bt[l+1]=='L')p[nt[l]].ans=p[nt[l+1]].ans=(at[l+1]+at[l])/2;
			else break;
		}
		for(r=t;r>1;r-=2)
		{
			if(bt[r]=='R' && bt[r-1]=='R')p[nt[r]].ans=p[nt[r-1]].ans=(m-at[r-1]+m-at[r])/2;
			else break;
		}
		//printf("l:%d r:%d\n",l,r);
		if(l<r)p[nt[l]].ans=p[nt[r]].ans=(at[l]+m-at[r]+m)/2;
		sort(p+1,p+n+1,cmp1);
		for(int i=1;i<=n;++i)printf("%d%c",p[i].ans,i==n? '\n':' ');
	}
	return 0;
}