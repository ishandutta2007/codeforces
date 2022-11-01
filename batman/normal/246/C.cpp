#include <bits/stdc++.h>
using namespace std;
int n,k,a[55];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int l=1;l<=n;l++)
		for(int i=n-l;i>=0;i--)
		{
			cout<<l<<" ";
			for(int j=n-1;j>n-l;j--)
				cout<<a[j]<<" ";
			cout<<a[i]<<"\n";	
			k--;
			if(!k)
				return 0;
		}
    return 0;
}