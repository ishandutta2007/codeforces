#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],t,n;
int sum1[1000005],sumn[1000005];
int sum[1000005];
inline int cal(int x,int y)
{
	return a[x]*a[y]+t*(a[x]+a[y]);
}
inline int CAL(int x)
{
	t=x;
	int qwq=cal(1,n);
	int l=2,r=n-1,pos=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(cal(1,mid)<cal(mid,n)) pos=mid,r=mid-1;
		else l=mid+1;
	}
	qwq+=sum1[n-1]-sum1[pos-1];
	qwq+=a[1]*t*(n-1-pos+1);
	qwq+=t*(sum[n-1]-sum[1]);
	qwq+=sumn[pos-1]-sumn[1];
	qwq+=a[n]*t*(pos-1-2+1);
//	for(int i=pos;i<n;i++) qwq+=cal(i,1);
//	for(int i=2;i<pos;i++) qwq+=cal(i,n);
/*	for(int j=2;j<n;j++)
	{
		qwq+=min(cal(1,j),cal(j,n));
		if(cal(1,j)<cal(j,n)) cout << j << " ";
	}
	cout << "\n";*/
	return qwq;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			sum1[i]=a[1]*a[i];
			sumn[i]=a[n]*a[i];
			sum[i]=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			sum1[i]+=sum1[i-1];
			sumn[i]+=sumn[i-1];
			sum[i]+=sum[i-1];
		}
		int mx=-1e18;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,CAL(a[i]));
			mx=max(mx,CAL(-a[i]));
		}
		int INF=2e6;
		if(CAL(INF+1)>CAL(INF)||CAL(-INF-1)>CAL(-INF))
		{
			cout << "INF\n";
		}
		else cout << mx << "\n";
	}
	return 0;
}