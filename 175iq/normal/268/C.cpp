
#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	int ans=min(m,n)+1;
	cout<<ans<<endl;

	int x,y;
	if(n<m)
	{
		x=0;
		y=1;
		for (int i = 0; i < ans; ++i)
		{
			cout<<x<<" "<<y<<endl;
			x++;
			y++;
		}
	}
	else if(n>m)
	{
		x=1;
		y=0;
		for (int i = 0; i < ans; ++i)
		{
			cout<<x<<" "<<y<<endl;
			x++;
			y++;
		}
	}
	else if(n==m)
	{	
		x=n;
		y=0;
		for (int i = 0; i < ans; ++i)
		{
			cout<<x<<" "<<y<<endl;
			x--;
			y++;
		}		
	}
	return 0;
}