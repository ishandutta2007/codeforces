#include<bits/stdc++.h>
using namespace std;
int l,cnt,t,t1,ans=0;
char s[5002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	scanf("%s",s),l=strlen(s);
	for(int i=0;i<l;++i)
	{
		cnt=t=0;
		for(int j=i;j<l;++j)
		{
			if(s[j]=='(')++cnt;
			else if(s[j]==')')--cnt;
			else ++t;
			if(cnt<t)++cnt,--t;
			if(cnt+t<0)break;
			if(((j-i)&1) && cnt-t<=0)++ans;
		}
	}
	printf("%d",ans);
	return 0;
}