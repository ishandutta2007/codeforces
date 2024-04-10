#include<bits/stdc++.h>
using namespace std;
int a[300005];
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int z=x;
	x=y,y=z-a/b*y;
}
int niyuan(int a)
{
	int x,y;
	exgcd(a,998244353,x,y);
	return (x%998244353+998244353)%998244353;
}
int main()
{
	int n;
	cin>>n;
	int aa=1,bb=1;
	for(int i=1;i<=2*n;i++)aa=1ll*aa*i%998244353;
	for(int i=1;i<=n;i++)bb=1ll*bb*i%998244353;
	int nn=1ll*niyuan(bb)*niyuan(bb)%998244353;
	int ans=1ll*aa*nn%998244353;
	long long pp=0;
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	for(int i=1;i<=n;i++)pp-=a[i],pp+=a[i+n];
	pp%=998244353;
	cout<<ans*pp%998244353<<endl;
	return 0;
}