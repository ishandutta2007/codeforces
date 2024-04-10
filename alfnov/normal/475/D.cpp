#include<bits/stdc++.h>
using namespace std;
int a[100005],q1[100005],q2[100005],q3[100005],q4[100005];
map<int,long long>mp;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
void merg(int l,int r)
{
	if(l==r)
	{
		mp[a[l]]++;
		return;
	}
	int mid=l+r>>1;
	merg(l,mid);
	merg(mid+1,r);
	int t1=0,t2=0,a1=a[mid],a2=a[mid+1];
	for(int i=mid;i>=l;i--)
	{
		int b=gcd(a1,a[i]);
		if(b<a1)
		{
			t1++;
			q1[t1]=i,q3[t1]=a1;
		}
		a1=b;
	}
	t1++;
	q1[t1]=l-1,q3[t1]=a1;
	q1[0]=mid;
	for(int i=mid+1;i<=r;i++)
	{
		int b=gcd(a2,a[i]);
		if(b<a2)
		{
			t2++;
			q2[t2]=i,q4[t2]=a2;
		}
		a2=b;
	}
	t2++;
	q2[t2]=r+1,q4[t2]=a2;
	q2[0]=mid+1;
	for(int i=1;i<=t1;i++)for(int j=1;j<=t2;j++)
		mp[gcd(q3[i],q4[j])]+=1ll*(q1[i-1]-q1[i])*(q2[j]-q2[j-1]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	merg(1,n);
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",mp[x]);
	}
	return 0;
}