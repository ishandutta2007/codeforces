#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long int x;
	cin>>n>>x;
	std::vector <pair <char,int> > vec;
	char a;
	int b;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		vec.push_back(make_pair(a,b));
	}
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if (vec[i].first=='+')
		{
			x+=vec[i].second;
		}
		else
		{
			if(x>=vec[i].second)
			{
				x-=vec[i].second;
			}
			else
			{
				count++;
			}
		}
	}
	cout<<x<<" "<<count;
	return 0;
}