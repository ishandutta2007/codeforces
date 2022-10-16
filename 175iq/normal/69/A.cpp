#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int x,y,z;
	int sum_x=0,sum_y=0,sum_z=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y>>z;
		sum_x+=x;
		sum_y+=y;
		sum_z+=z;
	}
	if((!sum_x) && (!sum_y) && (!sum_z))
	{
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
}