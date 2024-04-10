#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,l,Test_num;
int cnt[26];
char s[102],t[102];
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
		scanf("%s%s",s+1,t+1),l=strlen(s+1);
		for(int i=0;i<26;++i)cnt[i]=0;
		for(int i=1;i<=l;++i)++cnt[s[i]-'a'];
		if(t[1]=='a' && t[2]=='b' && t[3]=='c' && cnt[0] && cnt[1] && cnt[2])
		{
			for(int i=0;i<26;i=(i==0? 2:(i==2? 1:(i==1? 3:(i+1)))))for(int j=1;j<=cnt[i];++j)printf("%c",i+'a');
			puts("");
		}
		else
		{
			for(int i=0;i<26;++i)for(int j=1;j<=cnt[i];++j)printf("%c",i+'a');
			puts("");
		}
	}
	return 0;
}