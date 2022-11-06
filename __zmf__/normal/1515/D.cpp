//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int taxi,n,l,r,pos,k;
int a[200009],ans;
int cnt[200009];
inline bool cmp(int xxx,int yyy)
{
	return xxx>yyy;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();l=read(),r=read();
		for(int i=1;i<=n;i++)a[i]=read(),cnt[i]=0;
		if(l<r)
		{
			swap(l,r);
			reverse(a+1,a+n+1);
		}
		pos=n/2;
		for(int i=1;i<=l;i++)cnt[a[i]]++;
		for(int i=l+1;i<=n;i++)
			if(cnt[a[i]]>0)cnt[a[i]]--;
	//	for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";cout<<endl;
		sort(cnt+1,cnt+n+1,cmp);
		k=l-pos;
		for(int i=1;i<=n;i++)
			while(cnt[i]>=2&&k>0)cnt[i]-=2,k--;
		for(int i=1;i<=n;i++)
			while(cnt[i]>=1&&k>0)cnt[i]--,k--;
		ans=l-pos;
	//	cout<<ans<<endl;
		for(int i=1;i<=n;i++)ans=ans+cnt[i];
		cout<<ans<<endl;
	}
	return 0;
}