#include <bits/stdc++.h>
using namespace std;


bool myfunction(pair<int,int> &x, pair<int,int> &y)
{
	return (x.first < y.first) ;
}

int main()
{
	int n ;
	cin>>n ;
	int a,b ;
	std::vector<pair<int,int> > vec;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		vec.push_back(make_pair(a,b));
	}
	sort(vec.begin(),vec.end(),myfunction);
	for (int i = 1; i < n; ++i)
	{
		if(vec[i].second < vec[i-1].second)
		{
			cout<<"Happy Alex";
			return 0;
		}
	}
	cout<<"Poor Alex";
	return 0;
}