//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,cnt[259],now,pos,k;
bool vis[400009];
char a[400009];
int main()
{
	n=read();k=read();
	cin>>a;
	for(int i=0;i<n;i++)cnt[a[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(now+cnt[i]<=k)
		{
			now+=cnt[i];continue;
		}
		int qwq=0,upd=k-now,cnt=0;
		while(cnt<upd)
		{
			if(a[qwq]==i+'a')cnt++,vis[qwq]=1;
			qwq++;
		}
		pos=i-1;break;
	}
	if(n==k)return 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=pos+'a')continue;
		if(vis[i]==1)continue;
		cout<<a[i];
	}
	return 0;
}