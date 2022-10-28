#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int x, y;
	cin>>x>>y;
	int chance=0;
	while(true)
	{
		int take=220;
		if(!chance)
		{
			while(x>0 && take-100>=0)
			{
				x--;
				take-=100;
			}
			while(y>0 && take-10>=0)
			{
				y--;
				take-=10;
			}
			if(take)
			{
				cout<<"Hanako";
				return 0;
			}
		}
		else
		{
			if(y>0 && take-10>=0)
			{
				take-=10;
				y--;
			}
			if(y>0 && take-10>=0)
			{
				take-=10;
				y--;
			}
			while(y>=10 && take-100>=0)
			{
				take-=100;
				y-=10;
			}
			while(x>0 && take-100>=0)
			{
				x--;
				take-=100;
			}
			if(take)
			{
				cout<<"Ciel";
				return 0;
			}
		}
		chance^=1;
	}
	return 0;
}