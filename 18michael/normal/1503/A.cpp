#include<bits/stdc++.h>
using namespace std;
int n,tot,Test_num,cnta,cntb;
char s[200002],a[200002],b[200002];
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
		read(n),scanf("%s",s),cnta=cntb=tot=0;
		for(int i=0;i<n;++i)tot+=(s[i]^48);
		if(s[0]!='1' || s[n-1]!='1' || (tot&1))
		{
			puts("NO");
			continue;
		}
		tot>>=1,puts("YES");
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0')
			{
				if(cnta>cntb)a[i]=')',b[i]='(',--cnta,++cntb;
				else a[i]='(',b[i]=')',++cnta,--cntb;
			}
			else
			{
				if(tot)a[i]=b[i]='(',++cnta,++cntb,--tot;
				else a[i]=b[i]=')',--cnta,--cntb;
			}
		}
		for(int i=0;i<n;++i)printf("%c",a[i]);puts("");
		for(int i=0;i<n;++i)printf("%c",b[i]);puts("");
	}
	return 0;
}