#include<bits/stdc++.h>
using namespace std;
struct apple
{
	long double ang;
	int wz;
	bool operator<(const apple &other)const
	{
		return ang<other.ang;
	}
	apple(long double ang=0,int wz=0):ang(ang),wz(wz){}
}ang[5005];
long long x[3005],y[3005];
int cent;
const double PI=acos(-1);
long double dis(int a,int b)
{
	return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+1.0*(y[a]-y[b])*(y[a]-y[b]));
}
long long C(int x)
{
	return 1ll*x*(x-1)*(x-2)/6;
}
long long CC(int x)
{
	return 1ll*x*(x-1)*(x-2)*(x-3)/24;
}
long long chaji(int a,int b,int c)
{
	return 1ll*(x[b]-x[a])*(y[c]-y[b])-1ll*(y[b]-y[a])*(x[c]-x[b]);
}
int ddd(int a,int b)
{
	if(y[a]-y[cent]<0&&y[b]-y[cent]>0)return 1;
	if(y[a]-y[cent]>0&&y[b]-y[cent]<0)return 0;
	if(chaji(a,cent,b)<0)return 0;
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cent=i;
		long long aa=CC(n-1);
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			ang[j].ang=acos((x[j]-x[i])/dis(i,j));
			if(y[j]-y[i]<0)ang[j].ang=2*PI-ang[j].ang;
			ang[j].wz=j;
		}
		ang[i]=-1;
		sort(ang+1,ang+n+1);
		for(int j=2;j<n;j++)if(ddd(ang[j].wz,ang[j+1].wz))
			swap(ang[j],ang[j+1]);
		for(int j=n+1;j<2*n;j++)
			ang[j].ang=ang[j-n+1].ang+2*PI,ang[j].wz=ang[j-n+1].wz;
		int ll=2;
		for(int j=2;j<=n;j++)
		{/*
			int ll=lower_bound(ang+2,ang+2*n,apple(ang[j].ang+PI,0))-ang-1;
			int gg=ang[ll+1-n+1].wz;
			if(ll<n)gg=ang[ll+1].wz;*/
			ll=max(ll,j);
			while(ll+1<2*n&&chaji(ang[j].wz,i,ang[ll+1].wz)<0)ll++;
			aa-=C(ll-j);
		}
		ans+=aa;
	}
	cout<<ans<<endl;
	return 0;
}