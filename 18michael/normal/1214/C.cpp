#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,ok=0;
char s[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		cnt+=(s[i]=='('? 1:-1);
		if(cnt<0)
		{
			if(ok)return 0&puts("No");
			cnt=0,ok=1;
		}
	}
	if(ok)--cnt;
	return 0&puts(cnt? "No":"Yes");
}