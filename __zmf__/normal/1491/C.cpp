#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=5009;
int n,a[N],res[N],taxi;
long long ans;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),res[i]=0;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]==1)
			{
				res[i+1]+=res[i];
				continue;
			}
			if(a[i]-1<res[i])
			{
				res[i+1]+=(res[i]-a[i]+1);
			}
			if(a[i]-res[i]>1)ans+=(a[i]-res[i]-1);
			if(a[i]>n-i)
			{
				a[i]=n-i;
			}
			while(a[i]!=1)
			{
				res[i+a[i]]++;a[i]--;res[i]--;
			}
			//if(res[i]>0)res[i+1]+=res[i];
			//cout<<ans<<" "<<a[i]<<" "<<res[i]<<endl;
		}
		ans=ans+max(0,(a[n]-res[n]-1));
		printf("%lld\n",ans);
	}
	return 0;
}