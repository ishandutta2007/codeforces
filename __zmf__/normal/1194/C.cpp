//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=109;
int cnt[256],flag;
char s[N],t[N],p[N];
int lens,lent,lenp,now1,now2,taxi;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		cin>>s>>t>>p;
		lens=strlen(s);
		lent=strlen(t);
		lenp=strlen(p);
		now1=0,now2=0;
		while(now1<lens&&now2<lent)
		{
			if(s[now1]==t[now2])now1++;
			now2++;
		}
		if(now1!=lens)
		{
			puts("NO");continue;
		}
		for(int i='a';i<='z';i++)cnt[i]=0;
		for(int i=0;i<lens;i++)cnt[s[i]]++;
		for(int i=0;i<lenp;i++)cnt[p[i]]++;
		for(int i=0;i<lent;i++)cnt[t[i]]--;
		for(int i='a';i<='z';i++)
			if(cnt[i]<0)flag=1;
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}