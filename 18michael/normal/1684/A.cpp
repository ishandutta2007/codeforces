#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int l,ans,Test_num;
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
		scanf("%s",s+1),l=strlen(s+1);
		if(l<=2)printf("%c\n",s[l]);
		else
		{
			ans=9;
			for(int i=1;i<=l;++i)ans=min(ans,s[i]^48);
			printf("%d\n",ans);
		}
	}
	return 0;
}