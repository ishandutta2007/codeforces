#include<bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
int a[200005],b[200005];
int main()
{
	int n,m;
	cin>>n>>m;
	scanf("%s%s",s+1,t+1);
	int wz=1;
	for(int i=1;i<=n;i++)
	{
		if(wz>m)break;
		if(s[i]==t[wz])a[wz]=i,wz++;
	}
	wz=m;
	for(int i=n;i>=1;i--)
	{
		if(wz<1)break;
		if(s[i]==t[wz])b[m-wz+1]=i,wz--;
	}
	int ans=0;
	for(int i=1;i<m;i++)ans=max(ans,b[m-i]-a[i]);
	cout<<ans<<endl;
	return 0;
}