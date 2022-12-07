#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=1000010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
char s[Maxn];
int n,a[Maxn],tc[30];
//struct Node{int v,x;};
map<int,int>cnt;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=0;j<26;j++)tc[j]=0;
		for(int j=1;j<=len;j++)tc[s[j]-'a']++;
		a[i]=0;
		for(int j=0;j<26;j++)
		a[i]|=((tc[j]&1)<<j);
//		cnt[a[i]]++;
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=cnt[a[i]];
//		printf("%d %d %lld\n",i,a[i],ans);
		for(int j=0;j<26;j++)ans+=cnt[(1<<j)^a[i]];
		cnt[a[i]]++;
	}
	printf("%lld",ans);
	
}