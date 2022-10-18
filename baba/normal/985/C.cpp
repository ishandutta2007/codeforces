#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k,l,i,m,a[100001], next, last, ans;

	cin>>n>>k>>l;
	m=n*k;

	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a, a+m);

	last=n-1;
	for(i=n-1;i>=0;i--)
	{
		if(a[k*i] - a[0] > l)
			last=i-1;
		else break;
	}

	ans=0;
	next=min(k*(last+1)-1,n-1);

	for(i=m-1;i>=0;i--)
	{
		if(i%k != 0 && a[i]-a[0]<=l)
		{
			next=i;
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(i<=last)
			ans+=a[k*i];
		else
		{
			if(next < 0) 
			{
				cout <<"0\n";
				return 0;
			}
			ans+=a[next];
			next--;
			if(next%k==0) next--;
		}
	}
	cout << ans << "\n";
	return 0;
}