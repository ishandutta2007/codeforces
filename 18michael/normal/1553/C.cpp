#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ans;
int prea0[12],prea1[12],preb0[12],preb1[12];
char s[12];
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
		scanf("%s",s+1),ans=10;
		for(int i=1;i<=5;++i)prea0[i]=prea0[i-1]+(s[2*i-1]!='1');
		for(int i=1;i<=5;++i)prea1[i]=prea1[i-1]+(s[2*i-1]!='0');
		for(int i=1;i<=5;++i)preb0[i]=preb0[i-1]+(s[2*i]!='1');
		for(int i=1;i<=5;++i)preb1[i]=preb1[i-1]+(s[2*i]!='0');
		for(int i=1;i<=5;++i)
		{
			if(prea1[i]-((i-1)-preb0[i-1])>5-(i-1)){ans=min(ans,2*i-1);break;}
			if(prea1[i]-(i-preb0[i])>5-i){ans=min(ans,2*i);break;}
		}
		for(int i=1;i<=5;++i)
		{
			if(preb1[i]-(i-prea0[i])>5-i){ans=min(ans,2*i);break;}
			if(i<5 && preb1[i]-((i+1)-prea0[i+1])>5-(i+1)){ans=min(ans,2*i+1);break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}