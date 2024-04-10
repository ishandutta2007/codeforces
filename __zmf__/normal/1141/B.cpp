//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,a[200009],now,ans;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int pp=1;
	while(a[pp]==1)pp++;
	int qq=n;
	while(a[qq]==1)qq--;
	ans=pp-1+n-qq;
	int now=1,res=0;
	while(now<=n)
	{
		if(a[now]==1)res++;
		else res=0;
		ans=max(ans,res);
		now++;
	}
	cout<<ans<<endl;
	return 0;
}
//cmll->zmf->zzm->dx->fyy->cmll