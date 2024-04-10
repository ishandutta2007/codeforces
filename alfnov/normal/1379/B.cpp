#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		long long m;
		cin>>l>>r>>m;
		for(int i=l;i<=r;i++)
		{
			int p=i-m%i;
			if(l+p<=r)
			{
				cout<<i<<" "<<l<<" "<<l+p<<endl;
				break;
			}
			if(r-p>=l)
			{
				cout<<i<<" "<<r-p<<" "<<r<<endl;
				break;
			}
			p=i-p;
			if(l+p<=r)
			{
				cout<<i<<" "<<l+p<<" "<<l<<endl;
				break;
			}
			if(r-p>=l)
			{
				cout<<i<<" "<<r<<r-p<<endl;
				break;
			}
		}
	}
	return 0;
}