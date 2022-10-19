#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
char c;
char s[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x)
{
	return (x>0 && x<=n);
}
inline bool calc(int x)
{
	return (check(x) && check(x+1) && check(x+2) && s[x]=='a' && s[x+1]=='b' && s[x+2]=='c');
}
int main()
{
	read(n),read(q),scanf("%s",s+1);
	for(int i=1;i<=n;++i)ans+=calc(i);
	for(int x;q--;)
	{
		read(x);
		do c=getchar();while(c!='a' && c!='b' && c!='c');
		ans-=calc(x-2)+calc(x-1)+calc(x),s[x]=c,ans+=calc(x-2)+calc(x-1)+calc(x),printf("%d\n",ans);
	}
	return 0;
}