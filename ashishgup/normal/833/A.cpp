#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int prod=a*b;
		int round1=round(cbrt(prod));
		if(a%round1 == 0 && b%round1 == 0)
		{
			if(round1==1)
			{
				if(a==1&&b==1)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
			else
				cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
	return 0;
}