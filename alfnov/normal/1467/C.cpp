#include<bits/stdc++.h>
using namespace std;
int l1[300005],l2[300005],l3[300005];
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)scanf("%d",&l1[i]);
	for(int i=1;i<=b;i++)scanf("%d",&l2[i]);
	for(int i=1;i<=c;i++)scanf("%d",&l3[i]);
	int m1=INT_MAX,m2=INT_MAX,m3=INT_MAX;
	long long h1=0,h2=0,h3=0,ans=0;
	for(int i=1;i<=a;i++)m1=min(m1,l1[i]),h1+=l1[i];
	for(int i=1;i<=b;i++)m2=min(m2,l2[i]),h2+=l2[i];
	for(int i=1;i<=c;i++)m3=min(m3,l3[i]),h3+=l3[i];
	for(int i=1;i<=a;i++)
	{
		ans=max(ans,m2-(l1[i]-(h2+h3-m2-m3))+abs(h1-l1[i]-m3));
		ans=max(ans,m3-(l1[i]-(h2+h3-m2-m3))+abs(h1-l1[i]-m2));
	}
	for(int i=1;i<=b;i++)
	{
		ans=max(ans,m1-(l2[i]-(h1+h3-m1-m3))+abs(h2-l2[i]-m3));
		ans=max(ans,m3-(l2[i]-(h1+h3-m1-m3))+abs(h2-l2[i]-m1));
	}
	for(int i=1;i<=c;i++)
	{
		ans=max(ans,m1-(l3[i]-(h1+h2-m1-m2))+abs(h3-l3[i]-m2));
		ans=max(ans,m2-(l3[i]-(h1+h2-m1-m2))+abs(h3-l3[i]-m1));
	}
	cout<<ans<<endl;
	return 0;
}