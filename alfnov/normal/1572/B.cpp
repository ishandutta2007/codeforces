#include<bits/stdc++.h>
using namespace std;
int a[200005],tot,ans[200005];
void add(int x)
{
	int b=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=b;
	ans[++tot]=x;
}
int ds(int l,int r)
{
	if(r-l>=3)
	{
		add(r-2),ds(l,r-2);
		if(a[r]==1)add(r-2);
		return 0;
	}
	int ff=4*a[l]+2*a[l+1]+a[l+2];
	if(ff==0||ff==3||ff==5||ff==6)
	{
		add(l);
		return 0;
	}
}
int sd(int l,int r)
{
	int cnt=0;
	for(int i=l;i<=r;i++)cnt+=a[i];
	if(cnt&1)return -1;
	if((r-l)%2==0)return ds(l,r);
	if(a[l]==0)return sd(l+1,r);
	if(a[r]==0)return sd(l,r-1);
	int flag=0;
	for(int i=r-2;i>l;i-=2)if(a[i]!=a[i+1])flag=i;
	if(!flag)return -1;
	for(int i=l+1;i<flag;i+=2)if(a[i]==0)add(i-1);
	for(int i=flag-1;i>=l;i-=2)add(i);
	return sd(flag+2,r);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		tot=0;
		if(sd(1,n)==-1)printf("NO\n");
		else
		{
			printf("YES\n%d\n",tot);
			for(int i=1;i<=tot;i++)printf("%d\n",ans[i]); 
		}
	}
	return 0;
}