#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,t,la,Test_num;
string s;
int dis[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int max(int a,int b)
{
	return a>b? a:b;
}
bool check(int d)
{
	t=d-1;
	for(int i=0;i<=t && t<n;++i)t=max(t,dis[i]+d);
	if(t>=n)return 1;
	return 0;
}
int binary_search()
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		la=-1,cin>>s,n=s.length();
		for(int i=0;i<n;++i)
		{
			if(s[i]=='R')la=i;
			dis[i]=la;
		}
		printf("%d\n",binary_search());
	}
	return 0;
}