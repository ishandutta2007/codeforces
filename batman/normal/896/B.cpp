#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1010)

ll n,m,c,a[N];

int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>c;
	ll l=1,r=n;
	while(1)
	{
		if(l>r)break;
		ll x,id;
		cin>>x;
		if(x<=c/2)
		{
			if(l==1){cout<<1<<endl;a[l]=x;l++;continue;}
			if(x>=a[l-1]){cout<<l<<endl;a[l]=x;l++;continue;}
			for(int i=1;i<l;i++)
				if(a[i]>x)
				{
					cout<<i<<endl;a[i]=x;
					break;
				}
			continue;
		}
		if(r==n){cout<<n<<endl;a[r]=x;r--;continue;}
		if(x<=a[r+1]){cout<<r<<endl;a[r]=x;r--;continue;}
		for(int i=n;i>r;i--)
			if(a[i]<x)
			{
				cout<<i<<endl;a[i]=x;
				break;
			}
	}
    return 0;
}