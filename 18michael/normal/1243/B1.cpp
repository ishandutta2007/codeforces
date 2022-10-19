#include<bits/stdc++.h>
using namespace std;
int n,t,ok,Test_num;
char s1[10002],s2[10002];
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
		read(n),scanf("%s%s",s1+1,s2+1),t=0,ok=1;
		for(int i=1;i<=n;++i)
			if(s1[i]!=s2[i])
			{
				if(!t)t=i;
				else
				{
					if(t<0 || (s1[t]!=s1[i] || s2[i]!=s2[t]))
					{
						ok=0;
						break;
					}
					t=-1;
				}
			}
		puts((t<=0 && ok)? "Yes":"No");
	}
	return 0;
}