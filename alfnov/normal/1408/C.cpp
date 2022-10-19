#include<bits/stdc++.h>
#define eps 1e-6
using namespace std;
int a[100005],n,l;
bool check(double wz,int tmp)
{
	double za=0,ya=0;
	int i;
	for(i=1;i<=n&&a[i]<wz;i++)za+=(a[i]-a[i-1]+0.0)/i;
	za+=(wz-a[i-1])/i;
	for(i=n;i>=1&&a[i]>wz;i--)ya+=(a[i+1]-a[i]+0.0)/(n-i+1);
	ya+=(a[i+1]-wz)/(n-i+1);
	if(tmp==1)printf("%.6f\n",za);
	if(za>ya||fabs(za-ya)<eps)return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>l;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[0]=0,a[n+1]=l;
		double ll=0,rr=l;
		while(rr-ll>eps)
		{
			double mid=(ll+rr)/2;
			if(check(mid,0))rr=mid;
			else ll=mid;
		}
		check(ll,1);
	}
	return 0;
}