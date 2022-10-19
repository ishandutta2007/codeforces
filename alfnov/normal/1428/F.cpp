#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int f[1000005];
long long d[1000005];
int main()
{
	int n,lx=0;
	cin>>n;
	scanf("%s",s+1);
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='0')
		{
			d[i]=d[i+1];
			for(int j=1;j<=lx;j++)f[j]=i+j;
			lx=0;
		}else
		{
			lx++;
			if(!f[lx])d[i]=d[i+1]+n-i+1;
			else d[i]=d[i+1]+f[lx]-i;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=d[i];
	cout<<ans<<endl;
	return 0;
}