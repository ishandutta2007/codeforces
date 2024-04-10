#include<bits/stdc++.h>
using namespace std;
int ls,lt,T,ok,Test_num;
int nx[100005][26];
char s[100005],t[100005];
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
		scanf("%s",s+1),scanf("%s",t+1),ls=strlen(s+1),lt=strlen(t+1),ok=0;
		for(int i=0;i<26;++i)nx[ls+1][i]=nx[ls+2][i]=0;
		for(int i=ls;i>0;--i)
		{
			for(int j=0;j<26;++j)
				nx[i][j]=nx[i+2][j];
			nx[i][s[i]-'a']=i;
		}
		T=1;
		for(int i=((ls^lt)&1);i<=ls;)
		{
			i=nx[i+1][t[T]-'a'];
			if(!i)break;
			if((++T)>lt)
			{
				ok=1;
				break;
			}
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}