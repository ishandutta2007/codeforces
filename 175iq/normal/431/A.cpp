#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(4,0) ;
	for (int i = 0; i < 4; ++i)
	{
		cin>>v[i];
	}
	string s;
	cin>>s;
	int sum=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='1')
		{
			sum+=v[0];
		}
		else if(s[i]=='2')
		{
			sum+=v[1];
		}
		else if(s[i]=='3')
		{
			sum+=v[2];
		}		
		else
		{
			sum+=v[3];
		}
	}
	cout<<sum;
	return 0;
}