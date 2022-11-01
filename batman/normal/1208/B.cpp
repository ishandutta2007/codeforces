#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define ld long double
#define N ((int)2010)

int n,a[N];
set <int> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=N;
	for(int i=0;i<=n;i++)
	{
		ans=min(ans,n-i);
		for(int j=n-1;j>=i;j--)
		{
			if(s.count(a[j]))
			{
				while(j<n-1)
				{
					j++;
					s.erase(a[j]);
				}
				break;
			}
			s.insert(a[j]);
			ans=min(ans,j-i);
		}
		if(i==n)break;
		if(s.count(a[i]))
			break;
		s.insert(a[i]);
	}
	cout<<ans;
	return 0;
}