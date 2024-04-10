#include<bits/stdc++.h>
using namespace std;
unsigned long long mo=111339248186143ull,bs[5000005],mm[5000005],mm2[5000005];
char s[5000005];
int f[5000005];
unsigned long long geth(int l,int r)
{
	return mm[r]-mm[l-1]*bs[r-l+1];
}
unsigned long long getfh(int l,int r)
{
	return mm2[l]-mm2[r+1]*bs[r-l+1];
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	bs[0]=1;
	for(int i=1;i<=n;i++)mm[i]=mm[i-1]*mo+s[i],bs[i]=bs[i-1]*mo;
	for(int i=n;i>=1;i--)mm2[i]=mm2[i+1]*mo+s[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(geth(1,i/2)!=getfh(i-i/2+1,i))continue;
		f[i]=f[i/2]+1,ans+=f[i];
	}
	cout<<ans<<endl;
	return 0;
}