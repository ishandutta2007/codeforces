//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,k,now,cnt,maxlen,sum[100009];
char s[100009];
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);now=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='0')now++;
		else if(now!=0)now--;
		else s[i]='0';
	}
	for(int i=1;i<=n;i++)cout<<s[i];
	return 0;
}