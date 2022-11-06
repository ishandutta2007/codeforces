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
char a[5009];
int n,cnta[5009],cntb[5009],ans;
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;i++)
		if(a[i]=='a')cnta[i]=cnta[i-1]+1,cntb[i]=cntb[i-1];
		else cntb[i]=cntb[i-1]+1,cnta[i]=cnta[i-1];
	if(cnta[n]==n||cntb[n]==n)
	{
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=max(ans,cnta[i-1]+cnta[n]-cnta[j]+cntb[j]-cntb[i-1]);
	cout<<ans<<endl;
	return 0;
}