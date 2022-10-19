#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,t,Test_num;
bool ok;
char s[1000002];
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
		scanf("%s",s),n=strlen(s),t=0,ok=1;
		for(int i=0;i<n;++i)
		{
			t+=(s[i]=='A'? 1:-1);
			if(t<0)
			{
				ok=0;
				break;
			}
		}
		puts((ok && s[n-1]=='B')? "YES":"NO");
	}
	return 0;
}