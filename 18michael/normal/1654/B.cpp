#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num,mn;
int mx[26];
char a[1000002];
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
		scanf("%s",a),n=strlen(a),mn=n;
		for(int i=0;i<26;++i)mx[i]=-1;
		for(int i=0;i<n;++i)mx[a[i]-'a']=max(mx[a[i]-'a'],i);
		for(int i=0;i<26;++i)if(~mx[i])mn=min(mn,mx[i]);
		for(int i=mn;i<n;++i)printf("%c",a[i]);
		puts("");
	}
	return 0;
}