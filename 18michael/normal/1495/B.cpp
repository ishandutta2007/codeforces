#include<bits/stdc++.h>
using namespace std;
int n,ans=0,Mx=-1,tim;
int a[100002];
int le[100002][2]={},ri[100002][2]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=2;i<=n;++i)
	{
		if(a[i]>a[i-1])le[i][0]=le[i-1][0]+1,le[i][1]=0;
		else le[i][1]=le[i-1][1]+1,le[i][0]=0;
	}
	for(int i=n-1;i;--i)
	{
		if(a[i]>a[i+1])ri[i][0]=ri[i+1][0]+1,ri[i][1]=0;
		else ri[i][1]=ri[i+1][1]+1,ri[i][0]=0;
	}
	for(int i=1;i<=n;++i)
	{
		if(le[i][1]>Mx)Mx=le[i][1],tim=1;
		else if(le[i][1]==Mx)++tim;
		if(ri[i][1]>Mx)Mx=ri[i][1],tim=1;
		else if(ri[i][1]==Mx)++tim;
	}
	for(int i=1,p,q;i<=n;++i)
	{
		p=min(le[i][0],ri[i][0]),q=max(le[i][0],ri[i][0]);
		if(p<=q-((q&1)^1) || q<Mx || tim>2)continue;
		++ans;
	}
	printf("%d",ans);
	return 0;
}